#include "Reverb_Main.h"

Reverb_Main::Reverb_Main()
{
    
}

Reverb_Main::~Reverb_Main()
{
    
}

void Reverb_Main::prepareReverb(double inSampleRate,int inNumChannels)
{
    mySampleRate = inSampleRate;
    numChannels = inNumChannels;
}

void Reverb_Main::processReverb(float* inAudio, float* outAudio, int inNumSamples)
{
    for (int i = 0; i < inNumSamples; i++)
    {
        
    }
}
