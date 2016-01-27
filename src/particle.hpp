// particle.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// Forward declarations
class Cell;

class Particle
{
    public:

        // Default constructor
        Particle( const Cell &cell, double position, double direction, double energy );

        // Friend functions //
        friend std::ostream &operator<< ( std::ostream &out, const Particle &obj );

    private:

        // Const reference to particle cell
        const Cell &cell_;

        // Particle position in cell
        double position_;

        // Particle direction cosine
        double direction_;

        // Particle energy
        double energy_;
};

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj );
