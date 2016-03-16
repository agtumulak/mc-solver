// segmentrng.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
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
    fiss_nu_round_up_dists_( segment.MaterialReference().FissNu().BernoulliDistirbutions() )
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
unsigned int SegmentRng::SampleFissionNu( double energy )
{
    bool round_up = fiss_nu_round_up_dists_[ energy ]( generator_ );
    if( round_up )
    {
        return (unsigned int) ceil( segment_.MaterialReference().FissNu().at( energy ) );
    }
    else if( !round_up )
    {
        return (unsigned int) floor( segment_.MaterialReference().FissNu().at( energy ) );
    }
    else
    {
        assert( false );
        return 0;
    }
}
