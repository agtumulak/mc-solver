// segmentrng.cpp
// Aaron G. Tumulak

// std includes
#include <cmath>
#include <iostream>

// mc-solver includes
#include "segmentrng.hpp"

// Default constructor
SegmentRng::SegmentRng( std::default_random_engine &generator, const Segment &segment ):
    generator_( generator ),
    segment_( segment ),
    cell_source_dist_( uniform_dist( std::nextafter( 0.0, 0.1 ), segment_.CellWidth() ) ),
    isotropic_dist_( uniform_dist( -1.0, std::nextafter( 1.0, 1.1 ) ) ),
    group_source_dist_( segment.MaterialReference().ExtSource().GroupDistribution() ),
    next_event_dists_( segment.MaterialReference().TotMacroXsec().ExponentialDistributions() ),
    interaction_dists_( segment.MaterialReference().InteractionDistributions() ),
    scatter_dists_( segment.MaterialReference().MacroScatXsec().DiscreteDistributions() ),
    fiss_chi_dist_( segment.MaterialReference().FissChi().GroupDistribution() ),
    nu_lower_( static_cast<unsigned int> ( floor ( segment.MaterialReference().FissNu() ) ) ),
    nu_upper_( static_cast<unsigned int> ( ceil ( segment.MaterialReference().FissNu() ) ) ),
    fiss_nu_dist_( bernoulli_dist( (double) nu_upper_ - segment.MaterialReference().FissNu() ) )
{}

// Sample cell position
double SegmentRng::SamplePosition()
{
    return cell_source_dist_( generator_ );
}

// Sample isotropic direction
double SegmentRng::SampleDirection()
{
    return isotropic_dist_( generator_ );
}

// Sample energy group
double SegmentRng::SampleEnergyGroup()
{
    unsigned int index = group_source_dist_( generator_ );
    return segment_.MaterialReference().ExtSource().energyat( index );
}

// Sample distance to next event
double SegmentRng::SampleDistanceNextEvent( double energy )
{
    return next_event_dists_[ energy ]( generator_ );
}

// Sample interaction
SegmentRng::Interaction SegmentRng::SampleInteraction( double energy )
{
    return static_cast<SegmentRng::Interaction>( interaction_dists_[ energy ]( generator_ ) );
}

// Sample scatter energy
double SegmentRng::SampleScatterEnergy( double energy )
{
    // Use total macroscopic cross section as source of energy groups
    return segment_.MaterialReference().TotMacroXsec().energyat( scatter_dists_[ energy ]( generator_ ) );
}

// Sample fission energy
double SegmentRng::SampleFissionEnergy()
{
    return segment_.MaterialReference().TotMacroXsec().energyat( fiss_chi_dist_( generator_ ) );
}

// Sample number of neutrons produced in fission event
double SegmentRng::SampleFissionNu()
{
    bool round_up = fiss_nu_dist_( generator_ );
    if( round_up )
    {
        return nu_upper_;
    }
    else
    {
        return nu_lower_;
    }
}

