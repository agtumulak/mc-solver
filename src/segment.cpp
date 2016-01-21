// segment.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"
#include "segment.hpp"

// Default constructor
Segment::Segment( Material material, double width, int num_cells ):
    material_( material ),
    width_( width ),
    num_cells_( num_cells )
{}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Segment &obj )
{
    out << "Width: \t" << obj.width_ << std::endl;
    out << "Number of cells: " << obj.num_cells_ << std::endl;
    out << "Material address: " << &obj.material_ << std::endl;
    out << "Material: \n\n" << obj.material_ << std::endl;

    return out;
}
