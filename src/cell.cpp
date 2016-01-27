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

// Spawn a source neutron
void Cell::SpawnSourceNeutron()
{
    Particle neutron1( rng_.SamplePosition(), rng_.SampleDirection(), rng_.SampleEnergyGroup() );
    std::cout << "Source neutron spawned from cell at: " << this << std::endl;
    std::cout << "Neutron address: " << &neutron1 << std::endl;
    std::cout << "Spawned neutron data: \n" << neutron1 << std::endl;
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
