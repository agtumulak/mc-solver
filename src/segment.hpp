// segment.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <vector>

// mc-solver includes
#include "material.hpp"

class Segment
{
    public:

        // Default constructor
        Segment( Material material, double width, int num_cells );

        // Accessors and mutators //



        // Friend functions //

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Segment &obj );

    private:

        // Material
        const Material material_;

        // Width
        const double width_;

        // Number of equally spaced cells
        const int num_cells_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Segment &obj );
