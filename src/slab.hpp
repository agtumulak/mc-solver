// slab.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "settings.hpp"

class Slab
{
    public:

        double test() const { return layout_.TotalSourceRate(); };

        // Default constructor
        Slab( const Settings &settings, const Layout &layout );

        // Friend functions //
 
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Slab &obj );

    private:

        // Spawn a source neutron
        void SpawnSourceNeutron();

        // Settings
        Settings settings_;

        // Layout
        Layout layout_;

        // Vector of cells
        Layout::cellvector data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj );
