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
    source_dist_( std::discrete_distribution<int>( layout_.SourceRates().begin(), layout_.SourceRates().end() ) ),
    energy_groups_( layout_.GenerateEnergyGroups() )
{}

// Solve fixed source problem
void Slab::FixedSourceSolve()
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
void Slab::ListTrackLengthEstimators() const
{
    for( auto energy_it = energy_groups_.begin(); energy_it != energy_groups_.end(); energy_it++ )
    {
        std::cout << "#mc_scalar_flux_group_" << *energy_it << "_mev" << std::endl;
        for( auto cell_it = cells_.begin(); cell_it != cells_.end(); cell_it++ )
        {
            std::cout << cell_it->TrackLengthEstimator( *energy_it );
            // Add EOL otherwise add comma
            if( cell_it == prev( cells_.end() ) )
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << ",";
            }
        }
        std::cout << "#end" << std::endl;
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
    Particle active_neutron = bank_.back();
    bank_.pop_back();
    active_neutron.Transport( bank_ );
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
