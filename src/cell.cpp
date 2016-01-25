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

// Spawn a source neutron
void Cell::SpawnSourceNeutron()
{
    std::cout << "Source neutron spawned from cell at: " << this << std::endl;
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Cell &obj )
{
    out << "Cell address: " << &obj << "\t";
    out << "Material address: " << &obj.material_;
    return out;
}
