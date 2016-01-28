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
#include "particle.hpp"
#include "segmentrng.hpp"
#include "settings.hpp"

class Slab
{
    public:

        // Spawn an isotropic source neutron, put in bank
        void SpawnSourceNeutron();

        // Take source neutron, remove from bank
        void TransportNeutron();

        // List particles in bank
        void ListBank() const;

        // List track length estimators
        void ListTrackLengthEstimators( double energy ) const;

        // Default constructor
        Slab( const Settings &settings, const Layout &layout );

        // Friend functions //
 
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Slab &obj );

    private:

        // Const Settings
        const Settings settings_;

        // Const Layout
        const Layout layout_;

        // Random number generator
        std::default_random_engine generator_;

        // Vector of SegmentRng for random number generation
        std::vector<SegmentRng> segment_rngs_;

        // Vector of cells
        std::vector<Cell> cells_;

        // Discrete distribution of source neutrons
        std::discrete_distribution<int> source_dist_;

        // Neutron bank
        std::vector<Particle> bank_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj );
