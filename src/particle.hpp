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
        Particle(
                const std::vector<Cell>::const_iterator &left,
                const std::vector<Cell>::const_iterator &right,
                const std::vector<Cell>::iterator &it,
                double position,
                double direction,
                double energy );

        // Transport particle
        void Transport( std::vector<Particle> &bank );

        // Friend functions //
        friend std::ostream &operator<< ( std::ostream &out, const Particle &obj );

    private:

        // Move particle if it crosses boundary
        void CrossBoundary( std::vector<Particle> &bank );

        // Make particle interact
        void Interact( std::vector<Particle> &bank );

        // Const iterator pointing to leftmost and rightmost cells
        const std::vector<Cell>::const_iterator left_;
        const std::vector<Cell>::const_iterator right_;

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
