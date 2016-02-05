// layout.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "segment.hpp"
#include "segmentrng.hpp"

// Default constructor
Layout::Layout()
{}

// Add segment to end
void Layout::AddToEnd( Material material, double width, unsigned int num_cells )
{
    assert( num_cells > 0 );
    data_.push_back( Segment( material, width, num_cells ) );
    source_rates_.insert( source_rates_.end(), num_cells, material.ExtSource().GroupSum() * width / num_cells );
}

// Generate SegmentRng object for use with Slab object
std::vector<SegmentRng> Layout::GenerateSegmentRngs( std::default_random_engine &generator ) const
{
    assert( !data_.empty() );
    std::vector<SegmentRng> output;
    // Iterate through each segment in layout
    for( auto it = data_.begin(); it != data_.end(); it++ )
    {
        output.push_back( SegmentRng( generator, *it ) );
    }
    return output;
}

// Generate cells for use with Slab object
std::vector<Cell> Layout::GenerateCells( std::vector<SegmentRng> &segment_rngs ) const
{
    assert( !data_.empty() );
    assert( data_.size() == segment_rngs.size() );
    std::vector<Cell> output;
    // Iterate through each segment in layout
    auto segment_it = data_.begin();
    auto segment_rngs_it = segment_rngs.begin();
    for(; segment_it != data_.end(); segment_it++, segment_rngs_it++ )
    {
        for( int i = 0; i != segment_it->NumCells(); i++ )
        {
            output.push_back( Cell( *segment_it, *segment_rngs_it ) );
        }
    }
    return output;
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
