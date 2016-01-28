// particle.cpp
// Aaron G. Tumulak

// std includes
#include <cmath>
#include <cassert>
#include <iostream>

// mc-solver includes
#include "cell.hpp"
#include "particle.hpp"

// Default constructor

Particle::Particle(
        const std::vector<Cell>::const_iterator &left,
        const std::vector<Cell>::const_iterator &right,
        const std::vector<Cell>::iterator &it,
        double position,
        double direction,
        double energy ):
    left_( left ),
    right_( right ),
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
        boundary_distance = it_->SegmentReference().CellWidth() / direction_;
    }
    else { assert( false ); };

    // Sample distance to next event
    next_event_distance = it_->SegmentRngReference().SampleDistanceNextEvent( energy_ );

    // Perform outcome //

    if( boundary_distance < next_event_distance )
    {
        // Move particle
        it_->TrackDistance( energy_, boundary_distance );
        CrossBoundary();
    }
    else if( next_event_distance < boundary_distance )
    {
        // Interact particle
        it_->TrackDistance( energy_, next_event_distance );
        // Currently only absorption is tested
    }
    else { assert( false ); };
}

// Move particle if it crosses boundary
void Particle::CrossBoundary()
{
    assert( direction_ != 0.0 );
    if( direction_ < 0.0 )
    {
        if( it_ == left_ )
        {
            // Particle reaches vacuum and disappears
            position_ = std::nextafter( 0.0, 0.1 );
        }
        else
        {
            // Particle moves to left adjacent cell
            it_ = prev( it_ );
            position_ = std::nextafter( it_->SegmentReference().CellWidth(), 0.0 );
            Transport();
        }
    }
    else if( direction_ > 0.0 )
    {
        if( it_ == right_ )
        {
            // Particle reaches reflecting boundary
            position_ = std::nextafter( it_->SegmentReference().CellWidth(), 0.0 );
            direction_ = - direction_;
            Transport();
        }
        else
        {
            // Particle moves to right adjacent cell
            it_ = next( it_ );
            position_ = std::nextafter( 0.0, 0.1 );
            Transport();
        }
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
