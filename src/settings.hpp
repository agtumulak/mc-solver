// settings.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

class Settings
{
    public:

        // Default constructor
        Settings();

        // Accessors and mutators //

        void WriteSeed( unsigned int seed ) { seed_ = seed; }; 
        unsigned int Seed() const { return seed_; };

        void WriteHistories( unsigned int histories ) { histories_ = histories; };
        unsigned int Histories() const { return histories_; };

        // Friend functions //
 
        // Overload I/O operators
        friend std::ostream &operator<< ( std::ostream &out, const Settings &obj );

    private:

        // Random number seed
        unsigned int seed_;

        // Number of histories
        unsigned int histories_;
};

// Friend functions //

// Overload I/O operators
std::ostream &operator<< ( std::ostream &out, const Settings &obj );
