/*
  ==============================================================================

    ParticleComponent.cpp
    Created: 11 Feb 2017 2:04:03pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ParticleComponent.h"

//==============================================================================
ParticleComponent::ParticleComponent(Vector initialPosition, Vector initialVelocity, float newMass) : _mass(newMass)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    _position = initialPosition;
    _velocity = initialVelocity;
    
    setCentrePosition(_position[0], _position[1]);
    setSize(10, 10);
}

ParticleComponent::~ParticleComponent()
{
}

void ParticleComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    
    const float diameter {static_cast<float>(getLocalBounds().getHeight() - 1 * 2)};

    Path p;
    g.setColour(Colours::blue);
    p.addEllipse(getLocalBounds().getWidth() / 2 - diameter / 2, getLocalBounds().getHeight() / 2 - diameter / 2, diameter, diameter);
    g.fillPath(p);
}

void ParticleComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void ParticleComponent::clockUpdate() {
    // divide the velocity by the fraction of a second which has passed to work out how far the
    // particle will have moved
    _position[0] += _velocity[0] / (1 / TIMER_INTERVAL);
    _position[1] += _velocity[1] / (1 / TIMER_INTERVAL);
    setCentrePosition(_position[0], _position[1]);
}

void ParticleComponent::applyForce(Vector force) {
    // calculate the acceleration produced by the force, and the change in velocity produced
    Vector acceleration {force[0] / _mass, force[1] / _mass};
    
    _velocity[0] += acceleration[0] / (1 / TIMER_INTERVAL);
    _velocity[1] += acceleration[1] / (1 / TIMER_INTERVAL);
}
