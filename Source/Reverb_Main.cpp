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
    
    allPassOne.prepareFilter(mySampleRate, 0.5f, 0.8321f, 0.7f, 240.f);
    allPassTwo.prepareFilter(mySampleRate, 0.8f, 0.969f, 0.4f, 82.0f);
    
    combFilterOne.prepareFilter(mySampleRate, 0.7f, 0.723f, 0.5f, 1426.0f);
    combFilterTwo.prepareFilter(mySampleRate, 0.7f, 1.257f, 0.78f, 1781.0f);
    combFilterThree.prepareFilter(mySampleRate, 0.7f, 0.893f, 0.24f, 1973.0f);
    combFilterFour.prepareFilter(mySampleRate, 0.7f, 1.111f, 0.548f, 2098.0f);
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
        
        float combOneSample = combFilterOne.processComb(preDelaySample, inChannel, inTime);
        float combTwoSample = combFilterOne.processComb(preDelaySample, inChannel, inTime);
        float combThreeSample = combFilterOne.processComb(preDelaySample, inChannel, inTime);
        float combFourSample = combFilterOne.processComb(preDelaySample, inChannel, inTime);
        
        float allPassOneSample = (combOneSample + combTwoSample + combThreeSample + combFourSample) * 0.125f;
        
        float allPassTwoSample = allPassOne.processAllPass(allPassOneSample, inChannel, inTime);
        float reverb = allPassTwo.processAllPass(allPassTwoSample, inChannel, inTime);
        
        float y = (1.0f - inMix) * sample + inMix * reverb;
        
        outAudio[i] = y;
    }
}
