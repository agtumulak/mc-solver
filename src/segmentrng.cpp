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
    scatter_dists_( segment.MaterialReference().MacroScatXsec().DiscreteDistributions() )
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

