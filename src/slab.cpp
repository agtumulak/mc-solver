// slab.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
#include <iostream>
#include <random>

// mc-solver includes
#include "layout.hpp"
#include "settings.hpp"
#include "slab.hpp"

// Default constructor
Slab::Slab( const Settings &settings, const Layout &layout ):
    settings_( settings ),
    layout_( layout ),
    generator_( std::default_random_engine( settings_.Seed() ) ),
    segment_rngs_( layout.GenerateSegmentRngs( generator_ ) ),
    cells_( layout_.GenerateCells( segment_rngs_ ) )
{}

// Spawn an isotropic source neutron
void Slab::SpawnSourceNeutron()
{
    std::discrete_distribution<int> source_dist( layout_.SourceRates().begin(), layout_.SourceRates().end() );
    cells_[ source_dist( generator_ ) ].SpawnSourceNeutron();
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj )
{
    out << "Settings:\n" << obj.settings_ << std::endl;
    for( auto it = obj.cells_.begin(); it != obj.cells_.end(); it++ )
    {
        out << "Cell index: " << it - obj.cells_.begin() << "\t";
        out << *it << std::endl;
    }
    return out;
}
