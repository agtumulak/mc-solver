// particle.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <vector>

// Forward declarations
class Cell;

class Particle
{
    public:

        // Default constructor
        Particle( std::vector<Cell>::iterator it, double position, double direction, double energy );

        // Transport particle
        void Transport();

        // Friend functions //
        friend std::ostream &operator<< ( std::ostream &out, const Particle &obj );

    private:

        // Return distance to boundary
        double BoundaryDistance() const;

        // Sample distance to next event
        double SampleNextEventDistance() const;

        // Iterator pointing to current cell
        std::vector<Cell>::iterator it_;

        // Particle position in cell
        double position_;

        // Particle direction cosine
        double direction_;

        // Particle energy
        double energy_;
};

// Friend functions //
std::ostream &operator<< ( std::ostream &out, const Particle &obj );
