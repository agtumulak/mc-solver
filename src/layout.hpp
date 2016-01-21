// layout.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "segment.hpp"

class Layout
{
    public:

        // Cell vector typedef
        typedef std::vector<Cell> cellvector;

        // Default constructor
        Layout();

        // Add segment to end
        void AddToEnd( Material material, double width, int num_cells );

        // Generate cells for use with Slab object
        cellvector GenerateCells() const;

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
