/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2019 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::functionObjects::NusseltNumber

Description

    The Nusselt number is the ratio of convective heat transfer to conductive heat 
    transfer across a boundary. This functionObject calculates the Nusselt Number based 
    on the difference of the average temperature values on the two input patches.
    If the field is to be selected as TMean, it is recommended to use it with fieldAverage.
    
    Examples of function object specification:
    
    Nu
    {
        type                NusseltNumber;
        functionObjectLibs  ("libNusseltNumber.so");

        L                  0.05;
        field              "TMean";
        fluidPatch         "inlet";
        solidPatch         "copperToAir";
    }
    
Usage
    \table
        Property     | Description                | Required    | Default value
        type         | type name: NusseltNumber   | yes         |
        L            | Charecteristics length in meter | yes    | 
        field        | the average difference of the two patches will be calculated  | yes | T
        fluidPatch   | name of the patch that gives the temperature at time zero | yes | 
        solidPatch   | name of the heat supply patch | yes | 

    \endtable    
    
See also
    Foam::functionObjects::fvMeshFunctionObject

SourceFiles
    NusseltNumber.C

\*---------------------------------------------------------------------------*/

#ifndef functionObjects_NusseltNumber_H
#define functionObjects_NusseltNumber_H

#include "fvCFD.H"
#include "functionObject.H"
#include "HashPtrTable.H"
#include "OFstream.H"
#include "fvMeshFunctionObject.H"
#include "logFiles.H"
#include "writeLocalObjects.H"
#include "Field.H"
#include "volFieldsFwd.H"
#include "cellSet.H"
#include "fluidThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                         Class NusseltNumber Declaration
\*---------------------------------------------------------------------------*/

class NusseltNumber
:
    public fvMeshFunctionObject
{
        scalar L_;
        volScalarField Nu;
        word field_;
        word patch0;
        word patch1;
        
protected:

    // Protected member data

public:

    //- Runtime type information
    TypeName("NusseltNumber");


    // Constructors

        //- Construct from Time and dictionary
        NusseltNumber
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict
        );

    //- Destructor
       virtual ~NusseltNumber();


    // Member Functions

        virtual bool read(const dictionary&) {return true;};
        
        virtual bool execute();
        
        scalar temperatureJump(const volScalarField& T);
        
        virtual bool write() {return true;};

    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const NusseltNumber&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
