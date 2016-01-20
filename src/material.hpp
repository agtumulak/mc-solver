// material.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>

// mc-solver includes
#include "groupdependent.hpp"
#include "groupgroupdependent.hpp"

class Material
{
    public:

        // Default constructor
        Material();

        // Accessors and mutators //

        void WriteNumberDensity( double value );

        void WriteMicroAbsXsec( double energy, double value );

        void WriteMicroScatXsec( double from_energy, double to_energy, double value );

        void WriteMicroFissXsec( double energy, double value );

        void WriteFissNu( double value );

        void WriteFissChi( double energy, double value );

        void WriteExtSource( double energy, double value );

        // Friend functions //
        
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Material &obj );

    private:

        // Number density
        double num_density_;

        // Microscopic absorption cross section
        GroupDependent micro_abs_xsec_;

        // Microscopic scattering cross section
        GroupGroupDependent micro_scat_xsec_;

        // Microscopic fission cross section
        GroupDependent micro_fiss_xsec_;

        // Average number of neutrons produced per fission, nu
        double fiss_nu_;

        // Distribution of prompt fission neutrons, chi
        GroupDependent fiss_chi_;

        // External source
        GroupDependent ext_source_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Material &obj );
