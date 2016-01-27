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
Particle Cell::SpawnSourceNeutron( std::vector<Cell>::iterator it )
{
    return Particle( it, rng_.SamplePosition(), rng_.SampleDirection(), rng_.SampleEnergyGroup() );
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
