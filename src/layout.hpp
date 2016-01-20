// layout.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <vector>

// mc-solver includes
#include "segment.hpp"

class Layout
{
    public:

        // Default constructor
        Layout();

        // Add segment to end
        void AddToEnd( Material material, double width, int num_cells );

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Layout &obj );

    private:

        // Layout typedef
        typedef std::vector<Segment> layout;

        // Layout of slab
        layout data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Layout &obj );
