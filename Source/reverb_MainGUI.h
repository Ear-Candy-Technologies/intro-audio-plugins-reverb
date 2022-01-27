#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "sliderLookAndFeel.h"

class reverb_MainGUI : public juce::Component
{
public:
    reverb_MainGUI(Reverb_MasterClassAudioProcessor&);
    
    ~reverb_MainGUI() override;
    
    void paint(juce::Graphics&) override;
    
    void resized() override;
    
    void createSlider();
    
    void createButton();
    
private:
    
    sliderLookAndFeel sliderFront;
    
    juce::Slider timeSlider, mixSlider, preDelaySlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixSliderAttachment, timeSliderAttachment, preDelaySliderAttachment;
    
    juce::TextButton reverbButton;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> reverbButtonAttachment;
    
    Reverb_MasterClassAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(reverb_MainGUI)
};
