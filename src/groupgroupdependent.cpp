// groupgroupdependent.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>

// mc-solver includes
#include "groupgroupdependent.hpp"

// Default constructor
GroupGroupDependent::GroupGroupDependent()
{}

// Read value
GroupDependent GroupGroupDependent::Read( double energy_group ) const
{
    // Check that group exists
    assert( data_.find( energy_group ) != data_.end() );

    // Return value
    return data_.at( energy_group );
}

// Write value
void GroupGroupDependent::Write( double energy_group, GroupDependent value )
{
    // Check input arguments are valid
    assert( energy_group > 0.0 );

    // Write value at energy_group
    data_[ energy_group ] = value; 
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const GroupGroupDependent &obj )
{
    for( auto it = obj.data_.begin(); it != obj.data_.end(); it++ )
    {
        out << "Group: " << std::scientific << it->first << std::endl;
        out << it->second << std::endl;
    }

    out << std::defaultfloat;

    return out;
}
