// mc-solver.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"

int main()
{

    // Create material mat_1 //
    
    Material mat_1;
    mat_1.WriteNumberDensity( 1.0 ); 

    // Absorption
    mat_1.WriteMicroAbsXsec( 0.1, 1.0 );

    // Scattering
    mat_1.WriteMicroScatXsec( 0.1, 0.1, 1.0 );
    mat_1.WriteMicroScatXsec( 0.1, 14.0, 0.0 );
    mat_1.WriteMicroScatXsec( 14.0, 0.1, 1.0 );
    mat_1.WriteMicroScatXsec( 14.0, 14.0, 0.0 );

    // Fission
    mat_1.WriteMicroFissXsec( 0.1, 1.0 );
    mat_1.WriteFissNu( 1.0 );
    mat_1.WriteFissChi( 0.1, 0.0 );
    mat_1.WriteFissChi( 14.0, 1.0 );

    // External source
    mat_1.WriteExtSource( 0.1, 1.0 );
    mat_1.WriteExtSource( 14.0, 1.0 );

    // Test
    std::cout << std::endl << mat_1;

    return 0;
}
