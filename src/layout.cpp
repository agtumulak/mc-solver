// layout.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "segment.hpp"

// Default constructor
Layout::Layout()
{}

// Add segment to end
void Layout::AddToEnd( Material material, double width, int num_cells )
{
    data_.push_back( Segment( material, width, num_cells ) );
}

// Generate cells for use with Slab object
std::vector<Cell> Layout::GenerateCells() const
{
    std::vector<Cell> output;
    assert( !data_.empty() );
    // Iterate through each segment in layout
    for( auto it = data_.begin(); it != data_.end(); it++ )
    {
        for( int i = 0; i != it->NumCells(); i++ )
        {
            output.push_back( Cell( it->MaterialReference(), it->Width() ) );
        }
    }
    return output;
}

// Calculate total source generation rate
double Layout::TotalSourceRate() const
{
    return  std::accumulate(
            data_.begin(), data_.end(), 0.0,
            []( const double &x, const Segment &s )
            {
                return x + s.MaterialReference().ExtSource().GroupSum() * s.Width();
            });
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Layout &obj )
{
    for( auto it = obj.data_.begin(); it != obj.data_.end(); it++ )
    {
        out << "Segment index: " << it - obj.data_.begin() << std::endl;
        out << *it << std::endl;
    }
    return out;
}
