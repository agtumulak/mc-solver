// groupdependent.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>

// mc-solver includes
#include "groupdependent.hpp"

// Default constructor
GroupDependent::GroupDependent()
{}

// Initialize constructor
GroupDependent::GroupDependent( double energy, double value ):
    data_( {{ energy, value }} )
{}

// Read value
double GroupDependent::at( double energy ) const
{
    // Check that group exists
    assert( data_.find( energy ) != data_.end() );

    // Return value
    return data_.at( energy );
}

// Write value
void GroupDependent::Write( double energy, double value )
{
    // Check input arguments are valid
    assert( energy > 0.0 && value >= 0.0 );

    // Write/overwrite value at energy
    data_[ energy ] = value;
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
