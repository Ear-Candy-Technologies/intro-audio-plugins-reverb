#include "Reverb_Filters.h"

Reverb_Filters::Reverb_Filters(){}

Reverb_Filters::~Reverb_Filters(){}

void Reverb_Filters::prepareFilter(double inSampleRate, float inFeedback, float inSpeed, float inDepth, float inDelayTime)
{
    mySampleRate = inSampleRate;
    myFeedbackGain = inFeedback;
    
    circularBuffer.prepareDelay(mySampleRate,
                                myFeedbackGain,
                                inSpeed,
                                inDepth);
    
    circularBuffer.setDelaySamples(inDelayTime);
}
 
float Reverb_Filters::processAllPass(float x, int inChannel, float inFeedback)
{
    myFeedbackGain = inFeedback;
    
    float y;
    
    float inDL = x + (-myFeedbackGain)*fb1[inChannel];
    
    float outDL = circularBuffer.processSample(inDL, inChannel);
    
    y = outDL + myFeedbackGain * inDL;
    
    fb1[inChannel] = outDL;
    
    return y;
}

float Reverb_Filters::processComb(float x, int inChannel, float inFeedback)
{
    myFeedbackGain = inFeedback;
    
    float y;
    
    float inDL = x + (-myFeedbackGain)*fb1[inChannel];
    
    float outDL = circularBuffer.processSample(inDL, inChannel);
    
    y = outDL;
    
    fb1[inChannel] = outDL;
    
    return y;
}
