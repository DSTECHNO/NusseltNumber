# NusseltNumber
This repository provides a function object and tutorial for the calculation of Nusselt number based on OpenFoam-8 libraries.


The Nusselt number is calculated for the two boundaries given as input.

Nu = Convective heat transfer / Conductive heat transfer

![nusselt](https://user-images.githubusercontent.com/90314532/202379512-8de10e3f-e609-4209-8341-456facd79b8f.PNG)

The nusselt number field is displayed on the cylinder boundary of the tutorial case.
![2](https://user-images.githubusercontent.com/92421699/202396386-d207e233-9ce8-485c-b628-138cba68cc2b.png)
**Figure 1.** Nusselt Number field display on a cylinder boundary.

Nusselt Number values calculated using our functionObject as a result of CFD simulation and obtained from experimental results were compared in a graphic.
![Nu2D](https://user-images.githubusercontent.com/92421699/202397085-a7e10df9-4d61-459a-a4af-c7d4390052cf.png)
**Figure 2.** Comparison of Nusselt Number.

https://www.youtube.com/watch?v=-jCMPmvqgcw&t=1s&ab_channel=EnderDemirel

**Note:** The reference list includes the publication from which the experimental values were drawn.


# Usage

**Step 1.** Compile the functionObject in OpenFOAM-8.

$wmake

**Step 2.** To run the tutorial:

$ cd /NusseltNumber/tutorial

$ ./Allrun

**Addition.** To delete functionObject:

$ cd /NusseltNumber

$ wclean

# References

P. Renze, K. Akermann, Simulation of Conjugate Heat Transfer in Thermal Processes with Open Source CFD, ChemEngineering 2019, 3, 59; doi:10.3390/chemengineering3020059

# Underlying Data
Zenodo:

# Developers 

Aras Dogan

Sibel Yilmaz

Mustafa Kuzay

Prof. Dr. Ender Demirel

# Acknowledgements

This study is part of a project that has received funding from the European Union’s Horizon 2020 research and innovation programme under grant agreement No 956059

# Licence

Copyright 2022 Design and Simulation Technologies Inc.

Distributed using the GNU General Public License (GPL), version 3; see the LICENSE file for details.
