// groupdependent.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <map>

class GroupDependent
{
        public:

            // Default constructor
            GroupDependent();

            // Read value
            double Read( double energy_group ) const;

            // Write value
            void Write( double energy_group, double value );

            // Friend functions //
            
            // Overload operator<<()
            friend std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );

        private:

            // Map typedef
            typedef std::map<double,double> groupmap;

            // Map of energy groups and values
            groupmap data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );
