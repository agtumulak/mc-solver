// cell.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "particle.hpp"
#include "cell.hpp"

// Default constructor
Cell::Cell( const Segment &segment, SegmentRng &segmentrng ):
    segment_( segment ),
    rng_( segmentrng )
{}

// Spawn a source neutron and place in bank
Particle Cell::SpawnSourceNeutron()
{
    return Particle( *this, rng_.SamplePosition(), rng_.SampleDirection(), rng_.SampleEnergyGroup() );
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
