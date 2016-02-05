# mc-solver

## Introduction
`mc-solver` is a Monte Carlo solver for neutron transport in slab geometry. It supports groupwise cross sections and scores scalar fluxes by energy group.

## Quick Start
From the project directory, do `/scripts/run.sh /path/to/output/file` to produce `/path/to/output/file.mat`, a Matlab file with each energy group's scalar flux. For now, the problem can be set up by editing `src/mc-solver.cpp` which I think is straightforward enough to edit for most material and geometry configurations.

## Building
From the project directory run `make` to build the executable `mc-solver`.

## Results
### Purely Absorbing Slab
A fixed source, purely absorbing problem has been done using `mc-solver` with 100000000 histories. The test slab is 100 cm thick with vacuum conditions at the left boundary (x = 0 cm) and reflecting conditions at the right boundary (x = 100 cm). The macroscopic absoroption cross section is 0.1 cm<sup>-1</sup>. The mean free path is 10 cm and the scattering ratio is 0. A comparison to the analytic solution is shown below.

![analytic-comparison](https://raw.githubusercontent.com/agtumulak/mc-solver/master/assets/analytic-comparison.png)

### Non-multiplying Slab With Absorption and Isotropic Scattering
A fixed source, non-multiplying medium has been done using `mc-solver` with 100000000 histories. The test slab is 100 cm thick with vacuum conditions at the left boundary (x = 0 cm) and reflecting conditions at the right boundary (x = 100 cm). The mean free path was fixed at 10 cm. The scattering ratio Σ<sub>s</sub>/Σ<sub>t</sub> was varied between 0, 0.5, 0.9 and compared with a method of characteristics (MOC) and discrete ordinates (sn-solver-2) solver below.

![moc-comparison](https://raw.githubusercontent.com/agtumulak/mc-solver/master/assets/scattering-ratio-comparison.png)

### Two-Group Repeating Slab
A fixed source, two-group, multiplying medium has been modeled using `mc-solver`. The test slab is 87.5 cm thick with vacuum conditions at the left boundary (x = 0 cm) and reflecting conditions at the right boundary (x = 87.5 cm). The mean free path of fast and thermal neutrons were both 10 cm. Material properties of the slab are given below.

![repeating-slab](https://raw.githubusercontent.com/agtumulak/mc-solver/master/assets/moderator-fuel-moderator-fuel-comparison-data.png)

A comparison of `mc-solver` with `sn-solver-2` is given below. The solution for `mc-solver` used 1000000 histories.

![repeating-slab](https://raw.githubusercontent.com/agtumulak/mc-solver/master/assets/moderator-fuel-moderator-fuel-comparison.png)

