#pragma once
#include "Reverb_CircularBuffer.h"

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
    
    double mySampleRate;
    int numChannels;
};
