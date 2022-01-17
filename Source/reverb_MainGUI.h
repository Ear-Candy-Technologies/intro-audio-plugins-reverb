#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class reverb_MainGUI : public juce::Component
{
public:
    reverb_MainGUI(Reverb_MasterClassAudioProcessor&);
    
    ~reverb_MainGUI() override;
    
    void paint(juce::Graphics&) override;
    
    void resized() override;
    
private:
    
    Reverb_MasterClassAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(reverb_MainGUI)
};
