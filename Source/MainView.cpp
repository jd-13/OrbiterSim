/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainView::MainView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    
    constexpr int init {0};
    
    if (init == 0) {
        _particles.push_back(new ParticleComponent({200, 200}, {0, 0}, 10000000000000));
        _particles.push_back(new ParticleComponent({150, 200}, {0, 10}, 100000));
        _particles.push_back(new ParticleComponent({130, 200}, {0, 7}, 100000));
        _particles.push_back(new ParticleComponent({190, 200}, {0, 30}, 100000));
        _particles.push_back(new ParticleComponent({20, 200}, {0, 4}, 100000));
        _particles.push_back(new ParticleComponent({500, 200}, {0, -1}, 100000));
    } else if (init == 1) {
        const double speed {12};
        const double mass {100000000000000};
        const double radius {100};
        const double centre {200};
        _particles.push_back(new ParticleComponent({centre-radius, centre}, {0, -speed}, mass));
        _particles.push_back(new ParticleComponent({centre, centre-radius}, {speed, 0}, mass));
        _particles.push_back(new ParticleComponent({centre+radius, centre}, {0, speed}, mass));
        _particles.push_back(new ParticleComponent({centre, centre+radius}, {-speed, 0}, mass));
    } else if (init == 2) {
        const double mass {100000000000000};
        const double centre {200};
        _particles.push_back(new ParticleComponent({centre-100, centre+10}, {10, -16}, mass));
        _particles.push_back(new ParticleComponent({centre, centre+10}, {-16, 10}, mass));
        _particles.push_back(new ParticleComponent({centre+100, centre-10}, {-8, -14}, mass));
    }
    
    
//    _particles.push_back(new ParticleComponent({200, 200}, {0, 10}, 10000000000000));
//    _particles.push_back(new ParticleComponent({250, 200}, {0, -10}, 10000000000000));
    
    for (ParticleComponent* particle : _particles) {
        addAndMakeVisible(particle);
    }

    
    startTimer(TIMER_INTERVAL * 1);
    //[/Constructor]
}

MainView::~MainView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    for (ParticleComponent* particle : _particles) {
        delete particle;
    }
    //[/Destructor]
}

//==============================================================================
void MainView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainView::timerCallback() {
    GravityField::applyForces(_particles);
    
    for (ParticleComponent* particle : _particles) {
        particle->clockUpdate();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainView" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
