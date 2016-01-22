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

            // Initialize constructor
            GroupDependent( double energy, double value );

            // Accessors and mutators //

            // Read value
            double at( double energy ) const;

            // Write value
            void Write( double energy, double value );

            // Sum all values
            double GroupSum() const;

            // Friend functions //
            
            // Overload operator<<()
            friend std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );

        private:

            // Pair typedef
            typedef std::pair<double,double> energyvalpair;

            // Map typedef
            typedef std::map<double,double> groupmap;

            // Map of energy groups and values
            groupmap data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );
