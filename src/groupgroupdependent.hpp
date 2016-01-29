// groupgroupdependent.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <map>
#include <random>

// mc-solver includes
#include "groupdependent.hpp"

class GroupGroupDependent
{
        public:

            // Default constructor
            GroupGroupDependent();

            // Map of discrete distributions of each group
            typedef std::map<double,std::discrete_distribution<int>> discrete_dist_map;
            discrete_dist_map DiscreteDistributions() const;

            // Accessors and mutators //

            // Read value
            GroupDependent at( double energy ) const;

            // Write value
            void Write( double energy_1, double energy_2, double value );

            // Friend functions //
            
            // Overload operator<<()
            friend std::ostream &operator<< ( std::ostream &out, const GroupGroupDependent &obj );

        private:

            // Map typedef
            typedef std::map<double,GroupDependent> groupgroupmap;

            // Map of energy groups and values
            groupgroupmap data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupGroupDependent &obj );
