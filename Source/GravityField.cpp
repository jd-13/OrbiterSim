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
        System systemExcludingCurrent = _createSystemExcludingIndex(iii, system);
        
        _applyForcesToParticle(*system[iii], systemExcludingCurrent);

    }
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
            
Vector GravityField::_calculateForce(const ParticleComponent& particle1,
                                     const ParticleComponent& particle2) {
    constexpr double GRAVITATIONAL_CONSTANT {0.000000000667408};
    //constexpr double GRAVITATIONAL_CONSTANT {0.0667408};

    
    // calcuate the force to apply
    const double distance {
        std::sqrt(std::pow(particle1.getPosition()[0] - particle2.getPosition()[0], 2)
                  + std::pow(particle1.getPosition()[1] - particle2.getPosition()[1], 2))
    };

    const double forceMagnitude {
        GRAVITATIONAL_CONSTANT
        * ((particle1.getMass() * particle2.getMass()) / std::pow(distance, 2))
    };
    
    // tan = o / a
    //
    const double angle {
        std::atan(std::abs(particle1.getPosition()[1] - particle2.getPosition()[1])
                  / std::abs(particle1.getPosition()[0] - particle2.getPosition()[0]))
    };
    
    
    Vector force {0.0, 0.0};

    // cos = a / h
    // a = cos * h
    //
    // sin = o / h
    // o = sin * h

    force[0] = std::cos(angle) * forceMagnitude;
    force[1] = std::sin(angle) * forceMagnitude;
    
    force[0] *= (particle1.getPosition()[0] > particle2.getPosition()[0]) ? -1 : 1;
    force[1] *= (particle1.getPosition()[1] > particle2.getPosition()[1]) ? -1 : 1;
    
    return force;
}

void GravityField::_applyForcesToParticle(ParticleComponent& particle, const System& system) {
    
    Vector totalForce {0.0, 0.0};

    for (ParticleComponent* otherParticle : system) {
        Vector thisForce = _calculateForce(particle, *otherParticle);
        
        totalForce[0] += thisForce[0];
        totalForce[1] += thisForce[1];
    }
    
    particle.applyForce(totalForce);
}
