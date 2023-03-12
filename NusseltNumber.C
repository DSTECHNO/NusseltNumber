/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2019 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "NusseltNumber.H"
#include "dictionary.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(NusseltNumber, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        NusseltNumber,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::NusseltNumber::NusseltNumber
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fvMeshFunctionObject(name, runTime, dict),
    L_(dict.lookup<scalar>("L")),
    Nu
    (
        IOobject
        (
            "Nu",
            mesh_.time().timeName(),
            mesh_,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh_,
        dimensionedScalar("Nu", dimless, scalar(0.0))
    ),
    field_(dict.lookupOrDefault<word>("field","T")),
    patch0(dict.lookup("fluidPatch")),
    patch1(dict.lookup("solidPatch"))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::NusseltNumber::~NusseltNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //
scalar Foam::functionObjects::NusseltNumber::temperatureJump(const volScalarField& T)
{
    const int patch0ID =
        mesh_.boundaryMesh().findPatchID(patch0);
    const int patch1ID =
        mesh_.boundaryMesh().findPatchID(patch1);
    scalarField patch0Area = mesh_.magSf().boundaryField()[patch0ID];
    scalarField patch1Area = mesh_.magSf().boundaryField()[patch1ID];
    scalarField patch0Temp = T.boundaryField()[patch0ID];
    scalarField patch1Temp = T.boundaryField()[patch1ID];
    scalar patch0AvgTemp = gSum(patch0Area * patch0Temp) / gSum(patch0Area);
    scalar patch1AvgTemp = gSum(patch1Area * patch1Temp) / gSum(patch1Area);
        

    return mag(patch1AvgTemp - patch0AvgTemp)+1e-9;
}


bool Foam::functionObjects::NusseltNumber::execute()
{

    word fieldName = field_;
    if(!foundObject<volScalarField>(fieldName))
            fieldName = "T";
    const volScalarField& T = lookupObject<volScalarField>(fieldName);
    scalar deltaT = temperatureJump(T);
    
    forAll(mesh_.boundary(), pI)
    {
        if(mesh_.boundary()[pI].type() != "empty" && !(mesh_.boundary()[pI].coupled()))
        {
            scalarField Tp = T.boundaryField()[pI];
            scalarField Ti = T.boundaryField()[pI].patchInternalField();
            scalarField deltaX = mesh_.deltaCoeffs().boundaryField()[pI];
            scalarField dTdn=T.boundaryField()[pI].snGrad();
            
            Nu.boundaryFieldRef()[pI] = (-(Ti-Tp)*deltaX)/(deltaT)*L_;
        }
    }
    return true;
}

// ************************************************************************* //
