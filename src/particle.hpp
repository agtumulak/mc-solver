// particle.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

class Particle
{
    public:

        // Default constructor
        Particle( double position, double direction, double energy );

        // Friend functions //
        friend std::ostream &operator<< ( std::ostream &out, const Particle &obj );

    private:

        // Particle position in cell
        double position_;

        // Particle direction cosine
        double direction_;

        // Particle energy
        double energy_;
};

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj );
