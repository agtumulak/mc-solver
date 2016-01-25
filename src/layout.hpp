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

        // Default constructor
        Layout();

        // Add segment to end
        void AddToEnd( Material material, double width, int num_cells );

        // Generate cells for use with Slab object
        std::vector<Cell> GenerateCells() const;

        // Create vector of source rates for each cell
        std::vector<double> SourceRates() const;

        // Calculate total source generation rate
        double TotalSourceRate() const;

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
