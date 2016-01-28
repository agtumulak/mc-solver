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

// Run histories
void Slab::RunHistories()
{
    unsigned int histories = settings_.Histories();
    unsigned int progress_report_period = settings_.ProgressPeriod();
    for( unsigned int i = 0; i != histories; i++ )
    {
        if( i % progress_report_period == 0 )
        {
            double percent = (double) i / (double) histories * 100.0;
            std::cout << percent << "\% complete..." << std::endl;
        }
        SpawnSourceNeutron();
        while( !bank_.empty() )
        {
            PopNeutronAndTransport();
        }
    }
}

// List scalar fluxes at energy group
void Slab::ListTrackLengthEstimators( double energy ) const
{
    std::cout << "=>Track length estimators at energy: " << energy << std::endl;
    for( auto it = cells_.begin(); it != cells_.end(); it++ )
    {
        std::cout << it->TrackLengthEstimator( energy );
        // Add EOL otherwise add comma
        if( it == prev( cells_.end() ) )
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ",";
        }
    }
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

// Spawn an isotropic source neutron, put in bank
void Slab::SpawnSourceNeutron()
{
    assert( cells_.size() >= 2 );
    std::vector<Cell>::iterator it = next( cells_.begin(), source_dist_( generator_ ) );
    bank_.push_back( it->SpawnSourceNeutron( cells_.begin(), prev( cells_.end() ), it ) );
}

// Pop source neutron from bank and transport it
void Slab::PopNeutronAndTransport()
{
    Particle active_neutron = *prev( bank_.end() );
    active_neutron.Transport();
    bank_.pop_back();
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
