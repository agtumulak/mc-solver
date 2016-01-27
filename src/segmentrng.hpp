// segmentrng.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <random>

// mc-solver includes
#include "segment.hpp"

class SegmentRng
{
    public:

        // Default constructor
        SegmentRng( std::default_random_engine &generator, const Segment &segment );

        // Sample cell position
        double SamplePosition();

        // Sample isotropic direction
        double SampleDirection();

        // Sample energy group
        double SampleEnergyGroup();

        // Accessors and mutators //

        // Generator
        const std::default_random_engine &Generator() const { return generator_; };

    private:

        // Distribution typedefs
        typedef std::uniform_real_distribution<double> uniform_dist;
        typedef std::discrete_distribution<int> discrete_dist;

        // Reference to random number generator
        std::default_random_engine &generator_;

        // Const reference to segment
        const Segment &segment_;

        // Distribution for cell source position (0,cell_width)
        uniform_dist cell_source_dist_;

        // Distribution for isotropic direction cosine [-1,1]
        uniform_dist isotropic_dist_;

        // Distribution for cell source energy groups
        discrete_dist group_source_dist_;
};
