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
        const double &NumberDensity() const { return num_density_; };

        void WriteMicroAbsXsec( double energy, double value );

        void WriteMicroScatXsec( double from_energy, double to_energy, double value );

        void WriteMicroFissXsec( double energy, double value );

        void WriteFissNu( double value );

        void WriteFissChi( double energy, double value );

        void WriteExtSource( double energy, double value );
        const GroupDependent &ExtSource() const { return ext_source_; };

        const GroupDependent &TotMicroXsec() const { return tot_micro_xsec_; };

        // Friend functions //
        
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Material &obj );

    private:

        // Number density
        double num_density_;

        // Total microscopic cross section
        GroupDependent tot_micro_xsec_;

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
