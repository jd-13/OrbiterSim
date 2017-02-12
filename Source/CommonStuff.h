/*
  ==============================================================================

    CommonStuff.h
    Created: 11 Feb 2017 2:09:24pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef COMMONSTUFF_H_INCLUDED
#define COMMONSTUFF_H_INCLUDED

#include <vector>

// 1 Meter = 1 Pixel

typedef std::vector<double> Vector;
const double TIMER_INTERVAL {0.01}; // in seconds

class ParticleComponent;
typedef std::vector<ParticleComponent*> System;


#endif  // COMMONSTUFF_H_INCLUDED
