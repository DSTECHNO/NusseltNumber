# NusseltNumber
This repository provides a function object and tutorial for the calculation of Nusselt number based on OpenFoam-8 libraries.

Nu = Convective heat transfer / Conductive heat transfer

The Nusselt number is calculated for the two boundaries given as input.
The results are obtained as a field and the Nusselt Number value is displayed on the calculated boundary.

![1](https://user-images.githubusercontent.com/92421699/202169434-d9655785-ce9a-4e38-a7c5-3001e88f1f40.png)

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
