// groupgroupdependent.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <map>

// mc-solver includes
#include "groupdependent.hpp"

class GroupGroupDependent
{
        public:

            // Default constructor
            GroupGroupDependent();

            // Read value
            GroupDependent Read( double energy_group ) const;

            // Write value
            void Write( double energy_group, GroupDependent value );

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
