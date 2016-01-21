// slab.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "slab.hpp"

// Default constructor
Slab::Slab( const Layout &layout ):
    layout_( layout ),
    data_( layout_.GenerateCells() )
{}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj )
{
    for( auto it = obj.data_.begin(); it != obj.data_.end(); it++ )
    {
        out << "Cell index: " << it - obj.data_.begin() << "\t" << *it << std::endl;
    }
    return out;
}
