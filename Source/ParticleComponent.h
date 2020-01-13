/*
  ==============================================================================

    ParticleComponent.h
    Created: 11 Feb 2017 2:04:03pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef PARTICLECOMPONENT_H_INCLUDED
#define PARTICLECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CommonStuff.h"

//==============================================================================
/*
*/
class ParticleComponent    : public Component
{
public:
    ParticleComponent(Vector initialPosition, Vector initialVelocity, float newMass);
    ~ParticleComponent();

    void paint (Graphics&) override;
    void resized() override;
    
    double getMass() const {return _mass;}
    Vector getPosition() const {return _position;}
    
    void clockUpdate();
    void applyForce(Vector force);

private:
    double _mass;
    Vector _velocity;
    Vector _position;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParticleComponent)
};


#endif  // PARTICLECOMPONENT_H_INCLUDED
