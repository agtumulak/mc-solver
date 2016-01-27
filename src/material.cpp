// material.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"

// Default constructor
Material::Material()
{}

// Accessors and mutators //

// Number density
void Material::WriteNumberDensity( double value )
{
    num_density_ = value;
}

// Absorption cross section
void Material::WriteMicroAbsXsec( double energy, double value )
{
    micro_abs_xsec_.Write( energy, value );
    tot_micro_xsec_.Add( energy, value );
}

// Scattering cross section
void Material::WriteMicroScatXsec( double from_energy, double to_energy, double value )
{
    micro_scat_xsec_.Write( from_energy, to_energy, value );
    tot_micro_xsec_.Add( from_energy, value );
}

// Fission cross section
void Material::WriteMicroFissXsec( double energy, double value )
{
    micro_fiss_xsec_.Write( energy, value );
    tot_micro_xsec_.Add( energy, value );
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

    out << "Number density: " << obj.num_density_ << "\n" << std::endl;
    out << "Microscopic absorption cross section: \n" << obj.micro_abs_xsec_ << std::endl;
    out << "Microscopic scattering cross sections: \n" << obj.micro_scat_xsec_ << std::endl;
    out << "Microscopic fission cross section: \n" << obj.micro_fiss_xsec_ << std::endl;
    out << "Microscopic total cross section: \n" << obj.tot_micro_xsec_ << std::endl;
    out << "Average number of neutrons per fission, nu: " << obj.fiss_nu_ << "\n" << std::endl;
    out << "Energy distribution of fission neutrons, chi: \n" << obj.fiss_chi_ << std::endl;
    out << "External source: \n" << obj.ext_source_;

    out << std::defaultfloat;

    return out;
}
