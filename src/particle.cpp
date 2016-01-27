// particle.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "particle.hpp"

// Default constructor

Particle::Particle( std::vector<Cell>::iterator it, double position, double direction, double energy ):
    it_( it ),
    position_( position ),
    direction_( direction ),
    energy_( energy )
{}

// Transport particle
void Particle::Transport()
{}

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj )
{
    out << "Current cell: " << &(*obj.it_) << "\t";
    out << "Position: " << obj.position_ << "\t";
    out << "Direction: " << obj.direction_ << "\t";
    out << "Energy group: " << obj.energy_;
    return out;
}
