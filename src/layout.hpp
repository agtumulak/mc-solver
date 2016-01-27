// layout.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <random>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "segment.hpp"
#include "segmentrng.hpp"

class Layout
{
    public:

        // Default constructor
        Layout();

        // Add segment to end
        void AddToEnd( Material material, double width, unsigned int num_cells );

        // Generate SegmentRng object for use with Slab object
        std::vector<SegmentRng> GenerateSegmentRngs( std::default_random_engine &generator ) const;

        // Generate cells for use with Slab object
        std::vector<Cell> GenerateCells( std::vector<SegmentRng> &segment_rngs) const;

        // Accessors and mutators //

        // Vector of source rates for each cell
        const std::vector<double> &SourceRates() const { return source_rates_; };

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Layout &obj );

    private:

        // Layout of slab
        std::vector<Segment> data_;

        // Vector of source rates
        std::vector<double> source_rates_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Layout &obj );
