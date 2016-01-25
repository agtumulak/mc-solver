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
    generator_( std::default_random_engine( settings_.Seed() ) ),
    layout_( layout ),
    cells_( layout_.GenerateCells() ),
    source_rates_( layout_.SourceRates() )
{}

// Spawn a source neutron
void Slab::SpawnSourceNeutron()
{
    std::discrete_distribution<int> source_dist ( source_rates_.begin(), source_rates_.end() );
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
