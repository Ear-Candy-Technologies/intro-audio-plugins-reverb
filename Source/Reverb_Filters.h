#pragma once
#include "Reverb_CircularBuffer.h"
#include <JuceHeader.h>

class Reverb_Filters
{
public:
    
    Reverb_Filters();
    ~Reverb_Filters();
    
    void prepareFilter(double inSampleRate, float inFeedback, float inSpeed, float inDepth, float inDelayTime);
    
    float processAllPass(float x, int inChannel, float inFeedback);
    
    float processComb(float x, int inChannel, float inFeedback);
    
private:
    
    reverb_CirculaBuffer circularBuffer;
    
    float fb1[2] = {0.0f};
    
    double mySampleRate{0.0};
    float myFeedbackGain{0.5f};
    
};
