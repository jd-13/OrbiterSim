/*
  ==============================================================================

    GravityField.h
    Created: 11 Feb 2017 3:04:26pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef GRAVITYFIELD_H_INCLUDED
#define GRAVITYFIELD_H_INCLUDED

#include "CommonStuff.h"
#include "ParticleComponent.h"

struct CentreOfMass {
    double mass;
    Vector position;
};

class GravityField {
public:
    GravityField() = default;
    ~GravityField() = default;
    
    static void applyForces(System system);
    
private:
    /**
     * Finds the centre of mass of a system
     */
    static CentreOfMass _findCentreOfMass(System system);
    
    /**
     * Creates a system which contains all particles excluding the given index
     */
    static System _createSystemExcludingIndex(size_t index, System systemIn);
    
    /**
     * Applies the force to a single particle generated by the centre of mass supplied
     */
    static void _applyForceToParticle(ParticleComponent* particle, CentreOfMass CoMOfSystem);
    
};



#endif  // GRAVITYFIELD_H_INCLUDED
