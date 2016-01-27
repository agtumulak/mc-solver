// particle.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "particle.hpp"

// Default constructor
Particle::Particle( const Cell &cell, double position, double direction, double energy ):
    cell_( cell ),
    position_( position ),
    direction_( direction ),
    energy_( energy )
{}

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj )
{
    out << "Cell: " << &obj.cell_ << "\t";
    out << "Position: " << obj.position_ << "\t";
    out << "Direction: " << obj.direction_ << "\t";
    out << "Energy group: " << obj.energy_;
    return out;
}
