#pragma once
#include "Reverb_CircularBuffer.h"
#include "Reverb_Filters.h"

class Reverb_Main
{
public:
    
    Reverb_Main();
    ~Reverb_Main();
    
    void prepareReverb(double inSampleRate, int inNumChannels);
    
    void processReverb(float* inAudio,
                       float* outAudio,
                       int inNumSamples,
                       int inChannel,
                       float inPreDelay,
                       float inTime,
                       float inMix);
    
private:
    
    reverb_CirculaBuffer preDelay;
    
    Reverb_Filters allPassOne;
    Reverb_Filters allPassTwo;
    
    Reverb_Filters combFilterOne;
    Reverb_Filters combFilterTwo;
    Reverb_Filters combFilterThree;
    Reverb_Filters combFilterFour;
    
    double mySampleRate;
    int numChannels;
};
