// particle.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "particle.hpp"

// Default constructor
Particle::Particle( double position, double direction, double energy ):
    position_( position ),
    direction_( direction ),
    energy_( energy )
{}

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj )
{
    out << "Position: " << obj.position_ << "\t";
    out << "Direction: " << obj.direction_ << "\t";
    out << "Energy group: " << obj.energy_;
    return out;
}
