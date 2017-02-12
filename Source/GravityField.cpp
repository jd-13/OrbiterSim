/*
  ==============================================================================

    GravityField.cpp
    Created: 11 Feb 2017 3:04:26pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "GravityField.h"

void GravityField::applyForces(System system) {
    for (int iii {0}; iii < system.size(); iii++) {
        // Create a vector which contains all particles excluding the current one
        System systemExcludingCurrent {_createSystemExcludingIndex(iii, system)};
        
        // Calculate the centre of mass of the particles excluding the currently selected one
        CentreOfMass CoMExcludingCurrent = _findCentreOfMass(systemExcludingCurrent);
        
//        Logger::outputDebugString(String("COM: ") + String(CoMExcludingCurrent.position[0])
//                                  + " " + String(CoMExcludingCurrent.position[1]));
        
        // Apply the force create by the centre of mass
        _applyForceToParticle(system[iii], CoMExcludingCurrent);
    }
}

CentreOfMass GravityField::_findCentreOfMass(System system) {
    CentreOfMass retVal {0, {0, 0}};
    
    for (ParticleComponent* particle : system) {
        retVal.position[0] = (particle->getMass() * particle->getPosition()[0]
                             + retVal.mass * retVal.position[0])
                             / (particle->getMass() + retVal.mass);
        
        retVal.position[1] = (particle->getMass() * particle->getPosition()[1]
                             + retVal.mass * retVal.position[1])
                             / (particle->getMass() + retVal.mass);
        
        retVal.mass += particle->getMass();
    }
    
    return retVal;
    
}

System GravityField::_createSystemExcludingIndex(size_t index, System systemIn) {
    System systemOut;
    
    for (int iii {0}; iii < systemIn.size(); iii++) {
        if (iii != index) {
            systemOut.push_back(systemIn[iii]);
        }
    }
    
    return systemOut;
}

void GravityField::_applyForceToParticle(ParticleComponent* particle, CentreOfMass CoMOfSystem) {
    const double GRAVITATIONAL_CONSTANT {0.000000000667408};
    //const double GRAVITATIONAL_CONSTANT {0.00000667408};
    
    // calcuate the force to apply
    
    double distance {
        std::sqrt(std::pow(CoMOfSystem.position[0] - particle->getPosition()[0], 2)
                  + std::pow(CoMOfSystem.position[1] - particle->getPosition()[1], 2))
    };
    double forceMagnitude {
        GRAVITATIONAL_CONSTANT
        * ((particle->getMass() * CoMOfSystem.mass) / std::pow(distance, 2))
    };
    
    // tan = o / a
    //
    double angle {
        std::atan(std::abs(CoMOfSystem.position[1] - particle->getPosition()[1])
                  / std::abs(CoMOfSystem.position[0] - particle->getPosition()[0]))
    };
    
    
    Vector force {0, 0};

    // cos = a / h
    // a = cos * h
    //
    // sin = o / h
    // o = sin * h

    force[0] = std::cos(angle) * forceMagnitude;
    force[1] = std::sin(angle) * forceMagnitude;
    
    force[0] *= (CoMOfSystem.position[0] > particle->getPosition()[0]) ? 1 : -1;
    force[1] *= (CoMOfSystem.position[1] > particle->getPosition()[1]) ? 1 : -1;
    
    //Logger::outputDebugString(String("Forces: ") + String(force[0]) + " " + String(force[1]));
    
    particle->applyForce(force);
}