// slab.cpp
// Aaron G. Tumulak

// std includes
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

// mc-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "particle.hpp"
#include "settings.hpp"
#include "slab.hpp"

// Default constructor
Slab::Slab( const Settings &settings, const Layout &layout ):
    settings_( settings ),
    layout_( layout ),
    generator_( std::default_random_engine( settings_.Seed() ) ),
    segment_rngs_( layout.GenerateSegmentRngs( generator_ ) ),
    cells_( layout_.GenerateCells( segment_rngs_ ) ),
    source_dist_( std::discrete_distribution<int>( layout_.SourceRates().begin(), layout_.SourceRates().end() ) )
{}

// Spawn an isotropic source neutron, put in bank
void Slab::SpawnSourceNeutron()
{
    std::vector<Cell>::iterator it = next( cells_.begin(), source_dist_( generator_ ) );
    bank_.push_back( it->SpawnSourceNeutron( it ) );
}

// Take source neutron, remove from bank
void Slab::TransportNeutron()
{
    Particle active_neutron = *prev( bank_.end() );
    active_neutron.Transport();
    bank_.pop_back();
}

// List particles in bank
void Slab::ListBank() const
{
    std::cout << "Particle bank contents: " << std::endl;
    for( auto it = bank_.begin(); it != bank_.end(); it++ )
    {
        std::cout << *it << std::endl;
    }
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
