// cell.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"

class Cell
{
    public:

        // Default constructor
        Cell( const Material &material, double width );

        // Spawn a source neutron
        void SpawnSourceNeutron();

        // Friend functions //

        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Cell &obj );

    private:

        // Reference to material
        const Material &material_;

        // Cell width
        const double width_;

};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj );
