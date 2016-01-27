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
    assert( direction_ != 0.0 );

    // Determine possible outcomes //
    double boundary_distance = std::numeric_limits<double>::max();
    double next_event_distance = std::numeric_limits<double>::max();

    // Calculate distance to boundary
    if( direction_ < 0.0 )
    {
        boundary_distance = -1.0 * position_ / direction_;
    }
    else if( direction_ > 0.0 )
    {
        boundary_distance = ( it_->SegmentReference().Width() - position_ ) / direction_;
    }
    else { assert( false ); };

    // Sample distance to next event
    next_event_distance = it_->SegmentRngReference().SampleDistanceNextEvent( energy_ );

    // Perform outcome //

    if( boundary_distance < next_event_distance )
    {
        // Move particle
        it_->TrackDistance( boundary_distance );
    }
    else if( next_event_distance < boundary_distance )
    {
        // Interact particle
        it_->TrackDistance( next_event_distance );
    }
    else { assert( false ); };
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
