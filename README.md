# NusseltNumber
This repository provides a function object and tutorial for the calculation of Nusselt number based on OpenFoam-8 libraries.


The Nusselt number is calculated for the two boundaries given as input.

Nu = Convective heat transfer / Conductive heat transfer

![nusselt](https://user-images.githubusercontent.com/90314532/202379512-8de10e3f-e609-4209-8341-456facd79b8f.PNG)

The results are obtained as a field and the Nusselt Number value is displayed on the calculated boundary.

![1](https://user-images.githubusercontent.com/92421699/202171270-fabc4728-7189-4537-9569-38d6010a1bfc.png)
**Figure 1.** Nusselt Number field display on a cylinder boundary.

# Usage

**Step 1.** Compile the functionObject.

$wmake

**Step 2.** To run the tutorial:

$ cd /NusseltNumber/tutorial

$ ./Allrun

**Addition.** To delete functionObject:

$ cd /NusseltNumber

$ wclean

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
