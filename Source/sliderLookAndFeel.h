#pragma once
#include <JuceHeader.h>

class sliderLookAndFeel : public juce::LookAndFeel_V4
{
public:
    sliderLookAndFeel(){}
    
    virtual ~sliderLookAndFeel(){}
    
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&) override
    {
        auto radius = (float) juce::jmin(width / 2, height / 2) - 4.0f;
        auto centreX = (float) x + (float) width * 0.5f;
        auto centreY = (float) y + (float) height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        //fill color
        g.setColour(juce::Colour(111, 187, 211));
        g.fillEllipse(rx, ry, rw, rw);
        
        //outline color
        g.setColour(juce::Colours::royalblue);
        g.drawEllipse(rx, ry, rw, rw, 2.0f);
        
        juce::Path p;
        auto pointerLength = radius * 0.33f;
        auto pointerThickness = 3.0f;
        p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform(juce::AffineTransform::rotation (angle).translated(centreX, centreY));
        
        g.setColour(juce::Colours::royalblue);
        g.fillPath(p);
    }
    
private:
    
};
