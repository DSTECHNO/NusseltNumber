# NusseltNumber
This repository provides a function object and tutorial for the calculation of Nusselt number based on OpenFoam-8 libraries.


The Nusselt number is calculated for the two boundaries given as input.

Nu = Convective heat transfer / Conductive heat transfer

The results are obtained as a field and the Nusselt Number value is displayed on the calculated boundary.

![1](https://user-images.githubusercontent.com/92421699/202171270-fabc4728-7189-4537-9569-38d6010a1bfc.png)
**Figure 1.** Nusselt Number field display on a cylinder boundary.

# Usage

**Step 1.** Compile the functionObject.

$wmake

**Step 2.** cd tutorial/case

$./Allrun

**Addition.** To delete functionObject:

$cd NusseltNumber

$wclean

# Underlying Data
Zenodo:

# Licence

Copyright 2022 Design and Simulation Technologies Inc.

Distributed using the GNU General Public License (GPL), version 3; see the LICENSE file for details.
