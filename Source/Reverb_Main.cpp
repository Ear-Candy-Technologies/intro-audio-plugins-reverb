#include "Reverb_Main.h"

Reverb_Main::Reverb_Main(){}

Reverb_Main::~Reverb_Main(){}

void Reverb_Main::prepareReverb(double inSampleRate,int inNumChannels)
{
    mySampleRate = inSampleRate;
    numChannels = inNumChannels;
    
    preDelay.prepareDelay(mySampleRate,
                          0.0f,
                          0.0f,
                          0.0f);
}

void Reverb_Main::processReverb(float* inAudio,
                                float* outAudio,
                                int inNumSamples,
                                int inChannel,
                                float inPreDelay,
                                float inTime,
                                float inMix)
{
    
    float preDelaySec = inPreDelay * 0.001;
    float preDelayInSamples = preDelaySec * mySampleRate;
    
    preDelay.setDelaySamples(preDelayInSamples);
    
    for (int i = 0; i < inNumSamples; i++)
    {
        float sample = inAudio[i];
        
        float preDelaySample = preDelay.processSample(sample, inChannel);
        
        outAudio[i] = sample + (preDelaySample * 0.5f);
    }
}
