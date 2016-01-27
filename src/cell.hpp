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
        Particle SpawnSourceNeutron( std::vector<Cell>::iterator it );

        // Friend functions //

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Cell &obj );

    private:

        // Const reference to segment
        const Segment &segment_;

        // Reference to segmentrng
        SegmentRng &rng_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj );
