// particle.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
#include <iostream>

// mc-solver includes
#include "cell.hpp"
#include "particle.hpp"

// Default constructor

Particle::Particle( std::vector<Cell>::iterator it, double position, double direction, double energy ):
    it_( it ),
    position_( position ),
    direction_( direction ),
    energy_( energy )
{
    assert( direction_ != 0.0 );
}

// Transport particle
void Particle::Transport()
{
    std::cout << "Distance to boundary: " << BoundaryDistance() << std::endl;
    std::cout << "Distance to next event: " << SampleNextEventDistance() << std::endl;
}

// Return distance to boundary
double Particle::BoundaryDistance() const
{
    if( direction_ < 0.0 )
    {
        return -1.0 * position_ / direction_;
    }
    else if ( direction_ > 0.0 )
    {
        return ( it_->SegmentReference().Width() - position_ ) / direction_;
    }
    else {
        assert( false );
        return 0.0;
    };
}

// Sample distance to next event
double Particle::SampleNextEventDistance() const
{
    return it_->SegmentRngReference().SampleDistanceNextEvent( energy_ );
}

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj )
{
    out << "Current cell: " << &(*obj.it_) << "\t";
    out << "Position: " << obj.position_ << "\t";
    out << "Direction: " << obj.direction_ << "\t";
    out << "Energy group: " << obj.energy_;
    return out;
}
