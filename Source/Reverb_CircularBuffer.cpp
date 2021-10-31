#include "Reverb_CircularBuffer.h"

reverb_CirculaBuffer::reverb_CirculaBuffer(){}

reverb_CirculaBuffer::~reverb_CirculaBuffer(){}

void reverb_CirculaBuffer::prepareDelay(float inSampleRate,
                                        float inDelay,
                                        float inSpeed,
                                        float inDepth)
{
    myDepth = inDepth;
    myDelay = inDelay;
    
    if (inSpeed >= 0.1f && inSpeed <= 10.0f)
        angleChange = inSpeed * (1.f/inSampleRate) * 2 * VALOR_PI;
}

void reverb_CirculaBuffer::setDelaySamples(float delay)
{
    if (delay >= 1.f)
        myDelay = delay;
    else
        myDelay = 0.f;
}

float reverb_CirculaBuffer::processSample(float x, int channel)
{
    if (myDelay < 1.f)
        return x;
    else
    {
        float lfo;
        
        lfo = myDepth * sin(currentAngle[channel]);
        
        currentAngle[channel] += angleChange;
        if (currentAngle[channel] > 2.f * VALOR_PI)
            currentAngle[channel] -= 2.f * VALOR_PI;
        
        int d1 = floor(myDelay + lfo);
        int d2 = d1 + 1;
        float g2 = myDelay + lfo - (float)d1;
        float g1 = 1.0f - g2;
        
        int indexD1 = index[channel] - d1;
        if (indexD1 < 0)
            indexD1 += MAX_BUFFER_SIZE;
        
        int indexD2 = index[channel] - d2;
        if (indexD2 < 0)
            indexD2 += MAX_BUFFER_SIZE;
        
        float y = g1 * delayBuffer[indexD1][channel] + g2 * delayBuffer[indexD2][channel];
        
        delayBuffer[index[channel]][channel] = x;
        
        if (index[channel] < MAX_BUFFER_SIZE - 1)
            index[channel]++;
        else
            index[channel] = 0;
        
        return y;
    }
}
