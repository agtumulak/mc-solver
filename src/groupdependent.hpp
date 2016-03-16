// groupdependent.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <map>
#include <random>

class GroupDependent
{
        public:

            // Default constructor
            GroupDependent();

            // Initialize constructor
            GroupDependent( double energy, double value );

            // Sum all values
            double GroupSum() const;

            // Groupwise energy distribution of value at each group
            std::discrete_distribution<int> GroupDistribution() const;

            // Map of exponential distributions of each group
            typedef std::map<double,std::exponential_distribution<double>> exp_dist_map;
            exp_dist_map ExponentialDistributions() const;

            // Map of bernoulli distributions of each group. Success is defined
            // as being rounded up.
            typedef std::map<double,std::bernoulli_distribution> bernoulli_dist_map;
            bernoulli_dist_map BernoulliDistirbutions() const;

            // Accessors and mutators //

            // Read value
            double at( double energy ) const;

            // Write value
            void Write( double energy, double value );

            // Add value
            void Add( double energy, double value );

            // Read energy at index
            double energyat( unsigned int index ) const;

            // Iterators //

            // Const iterators to fastest and slowest group
            std::map<double,double>::const_iterator slowest() const { return data_.begin(); };
            std::map<double,double>::const_iterator fastest() const { return data_.end(); };

            // Friend functions //
            
            // Overload operator<<()
            friend std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );

        private:

            // Map of energy groups and values
            std::map<double,double> data_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj );
