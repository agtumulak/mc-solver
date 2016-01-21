// slab.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"

class Slab
{
    public:

        // Default constructor
        Slab( const Layout &layout );

        // Friend functions //
 
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Slab &obj );

    private:

        // Layout
        Layout layout_;

        // Vector of cells
        Layout::cellvector data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj );
