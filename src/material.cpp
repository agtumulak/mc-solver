// material.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"
#include "segmentrng.hpp"

// Default constructor
Material::Material()
{}

// Return a map of energy groups and distributions of interactions
std::map<double,std::discrete_distribution<int>> Material::InteractionDistributions() const
{
    std::map<double,std::discrete_distribution<int>> distributions;
    for( auto it = tot_macro_xsec_.slowest(); it != tot_macro_xsec_.fastest(); it++ )
    {
        double energy = it->first;
        // Create map of interaction probabilities
        std::map<SegmentRng::Interaction,double> probabilities;
        probabilities[ SegmentRng::ABSORPTION ] = macro_abs_xsec_.at( energy );
        probabilities[ SegmentRng::SCATTERING ] = macro_scat_xsec_.at( energy ).GroupSum();
        probabilities[ SegmentRng::FISSION ] = macro_fiss_xsec_.at( energy );
        // Construct vector of map values by increasing key
        std::vector<double> map_values;
        for( auto it = probabilities.begin(); it != probabilities.end(); it++ )
        {
            map_values.push_back( it->second );
        }
        distributions[ energy ] = std::discrete_distribution<int> ( map_values.begin(), map_values.end() );
    }
    return distributions;
}

// Accessors and mutators //

// Absorption cross section
void Material::WriteMacroAbsXsec( double energy, double value )
{
    macro_abs_xsec_.Write( energy, value );
    tot_macro_xsec_.Add( energy, value );
}

// Scattering cross section
void Material::WriteMacroScatXsec( double from_energy, double to_energy, double value )
{
    macro_scat_xsec_.Write( from_energy, to_energy, value );
    tot_macro_xsec_.Add( from_energy, value );
}

// Fission cross section
void Material::WriteMacroFissXsec( double energy, double value )
{
    macro_fiss_xsec_.Write( energy, value );
    tot_macro_xsec_.Add( energy, value );
}

// Average number of neutrons per fission, nu
void Material::WriteFissNu( double value )
{
    fiss_nu_ = value;
}

// Energy distribution of fission neutrons, chi
void Material::WriteFissChi( double energy, double value )
{
    fiss_chi_.Write( energy, value );
}

// External source
void Material::WriteExtSource( double energy, double value )
{
    ext_source_.Write( energy, value );
}

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Material &obj )
{
    out << std::scientific;

    out << "Macroscopic absorption cross section: \n" << obj.macro_abs_xsec_ << std::endl;
    out << "Macroscopic scattering cross sections: \n" << obj.macro_scat_xsec_ << std::endl;
    out << "Macroscopic fission cross section: \n" << obj.macro_fiss_xsec_ << std::endl;
    out << "Macroscopic total cross section: \n" << obj.tot_macro_xsec_ << std::endl;
    out << "Average number of neutrons per fission, nu: " << obj.fiss_nu_ << "\n" << std::endl;
    out << "Energy distribution of fission neutrons, chi: \n" << obj.fiss_chi_ << std::endl;
    out << "External source: \n" << obj.ext_source_;

    out << std::defaultfloat;

    return out;
}
