// groupdependent.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>

// mc-solver includes
#include "groupdependent.hpp"

// Default constructor
GroupDependent::GroupDependent()
{}

// Read value
double GroupDependent::Read( double energy_group ) const
{
    // Check that group exists
    assert( data_.find( energy_group ) != data_.end() );

    // Return value
    return data_.at( energy_group );
}

// Write value
void GroupDependent::Write( double energy_group, double value )
{
    // Check input arguments are valid
    assert( energy_group > 0.0 && value > 0.0 );

    // Write value at energy_group
    data_[ energy_group ] = value; 
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupDependent &obj )
{
    out << std::scientific;

    for( auto it = obj.data_.begin(); it != obj.data_.end(); it++ )
    {
        out << "Group: " << it->first << "\t" << "Value: " << it->second << std::endl;
    }

    out << std::defaultfloat;

    return out;
}
