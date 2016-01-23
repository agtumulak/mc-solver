// slab.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "layout.hpp"
#include "settings.hpp"
#include "slab.hpp"

// Default constructor
Slab::Slab( const Settings &settings, const Layout &layout ):
    settings_( settings ),
    layout_( layout ),
    data_( layout_.GenerateCells() )
{}

// Spawn a source neutron
void Slab::SpawnSourceNeutron()
{}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj )
{
    out << "Settings:\n" << obj.settings_ << std::endl;
    for( auto it = obj.data_.begin(); it != obj.data_.end(); it++ )
    {
        out << "Cell index: " << it - obj.data_.begin() << "\t" << *it << std::endl;
    }
    return out;
}
