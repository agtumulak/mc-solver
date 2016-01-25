// slab.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <random>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "settings.hpp"

class Slab
{
    public:

        double test1() const { return layout_.TotalSourceRate(); };

        // Spawn a source neutron
        void SpawnSourceNeutron();

        // Default constructor
        Slab( const Settings &settings, const Layout &layout );

        // Friend functions //
 
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Slab &obj );

    private:

        // Settings
        Settings settings_;

        // Random number generator
        std::default_random_engine generator_;

        // Layout
        Layout layout_;

        // Vector of cells
        std::vector<Cell> cells_;

        // Vector of source rates
        std::vector<double> source_rates_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj );
