// mc-solver.cpp
// Aaron G. Tumulak

// std includes
#include <iostream>

// mc-solver includes
#include "material.hpp"
#include "layout.hpp"
#include "settings.hpp"
#include "slab.hpp"

int main()
{

    // Create settings //
    
    Settings settings_1;
    settings_1.WriteSeed( 10 );
    settings_1.WriteHistories( 100 );

    // Create material mat_1 //
    Material mat_1;

    // Absorption
    mat_1.WriteMacroAbsXsec( 0.1, 1.0 );

    // Scattering
    mat_1.WriteMacroScatXsec( 0.1, 0.1, 1.0 );
    mat_1.WriteMacroScatXsec( 0.1, 14.0, 0.0 );
    mat_1.WriteMacroScatXsec( 14.0, 0.1, 1.0 );
    mat_1.WriteMacroScatXsec( 14.0, 14.0, 0.0 );

    // Fission
    mat_1.WriteMacroFissXsec( 0.1, 1.0 );
    mat_1.WriteFissNu( 1.0 );
    mat_1.WriteFissChi( 0.1, 0.0 );
    mat_1.WriteFissChi( 14.0, 1.0 );

    // External source
    mat_1.WriteExtSource( 0.1, 1.0 );
    mat_1.WriteExtSource( 14.0, 1.0 );

    // Create material mat_2 //
    Material mat_2;

    // Absorption
    mat_2.WriteMacroAbsXsec( 0.1, 2.0 );

    // Scattering
    mat_2.WriteMacroScatXsec( 0.1, 0.1, 2.0 );
    mat_2.WriteMacroScatXsec( 0.1, 14.0, 0.0 );
    mat_2.WriteMacroScatXsec( 14.0, 0.1, 2.0 );
    mat_2.WriteMacroScatXsec( 14.0, 14.0, 0.0 );

    // Fission
    mat_2.WriteMacroFissXsec( 0.1, 2.0 );
    mat_2.WriteFissNu( 1.0 );
    mat_2.WriteFissChi( 0.1, 0.0 );
    mat_2.WriteFissChi( 14.0, 1.0 );

    // External source
    mat_2.WriteExtSource( 0.1, 2.0 );
    mat_2.WriteExtSource( 14.0, 2.0 );

    // Create layout //
    Layout layout_1;
    layout_1.AddToEnd( mat_1, 100.0, 2 );
    layout_1.AddToEnd( mat_2, 50.0, 2 );
    layout_1.AddToEnd( mat_1, 400.0, 1 );

    // Create slab
    Slab slab_1( settings_1, layout_1 );

    // Test
    std::cout << slab_1 << std::endl;
    slab_1.SpawnSourceNeutron();
    slab_1.SpawnSourceNeutron();
    slab_1.ListBank();
    slab_1.TransportNeutron();
    
    return 0;
}
