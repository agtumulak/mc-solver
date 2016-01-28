// cell.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>
#include <vector>

// mc-solver includes
#include "particle.hpp"
#include "cell.hpp"

// Default constructor
Cell::Cell( const Segment &segment, SegmentRng &segmentrng ):
    segment_( segment ),
    rng_( segmentrng )
{}

// Spawn a source neutron
Particle Cell::SpawnSourceNeutron(
        const std::vector<Cell>::const_iterator &left,
        const std::vector<Cell>::const_iterator &right,
        const std::vector<Cell>::iterator &it )
{
    return Particle( left, right, it, rng_.SamplePosition(), rng_.SampleDirection(), rng_.SampleEnergyGroup() );
}

// Track particle movement distance
void Cell::TrackDistance( const double &energy, const double &distance )
{
    track_length_estimator_.Add( energy, distance );
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj )
{
    out << "Cell address: " << &obj << "\t";
    out << "Segment address: " << &obj.segment_ << "\t";
    out << "SegmentRng address: " << &obj.rng_ << "\t";
    out << "Generator address: " << &obj.rng_.Generator();
    return out;
}
