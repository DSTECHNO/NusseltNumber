# NusseltNumber
This repository provides a function object and tutorial for the calculation of Nusselt number based on OpenFoam libraries.
The functionObject must be compiled before using it.
Run the "wmake" command in the terminal.
To remove the functionObject, run the "wclean" command.

# Usage
Step 1. Compile the functionObject.
$wmake
Step 2. cd tutorial/case
$./Allrun
Addition. To delete functionObject:
$cd NusseltNumber
$wclean
