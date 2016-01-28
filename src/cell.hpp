// cell.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// mc-solver includes
#include "particle.hpp"
#include "segment.hpp"
#include "segmentrng.hpp"

class Cell
{
    public:

        // Default constructor
        Cell( const Segment &segment, SegmentRng &segmentrng );

        // Spawn a source neutron
        Particle SpawnSourceNeutron(
                const std::vector<Cell>::const_iterator &left,
                const std::vector<Cell>::const_iterator &right,
                const std::vector<Cell>::iterator &it );

        // Track particle movement distance
        void TrackDistance( const double &add_length ) { track_length_ += add_length; };

        // Accessors and mutators //

        // Return const reference to segment_
        const Segment &SegmentReference() const { return segment_; };

        // Return reference to rng_
        SegmentRng &SegmentRngReference() { return rng_; };

        // Friend functions //

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Cell &obj );

    private:

        // Const reference to segment
        const Segment &segment_;

        // Reference to segmentrng
        SegmentRng &rng_;

        // Track length estimator
        double track_length_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj );
