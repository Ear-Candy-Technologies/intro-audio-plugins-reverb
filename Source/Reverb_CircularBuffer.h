#pragma once
#include "math.h"
#include "Reverb_MathHelpers.h"

const int MAX_BUFFER_SIZE = 192000;

class reverb_CirculaBuffer
{
public:
    
    reverb_CirculaBuffer();

    ~reverb_CirculaBuffer();
    
    void prepareDelay(float inSampleRate,
                      float inDelay,
                      float inSpeed,
                      float inDepth);
    
    float processSample(float x, int channel);

    void setDelaySamples(float delay);

private:
    
    int index[2] = {0};
    
    float myDelay {5.0f}, myDepth {10.0f}, angleChange{0.0f};
    
    float delayBuffer[MAX_BUFFER_SIZE][2] = {0.0f}, currentAngle[2] = {0.0f};

};
