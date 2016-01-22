// cell.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"
#include "cell.hpp"

// Default constructor
Cell::Cell( const Material &material, double width ):
    material_( material ),
    width_( width )
{}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj )
{
    out << "Material address: " << &obj.material_;
    return out;
}
