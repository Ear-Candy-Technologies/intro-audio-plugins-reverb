#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class reverb_HeaderGUI : public juce::Component
{
public:
    reverb_HeaderGUI(Reverb_MasterClassAudioProcessor&);
    
    ~reverb_HeaderGUI() override;
    
    void paint(juce::Graphics&) override;
    
    void resized() override;
    
    void createLabel();
    
private:
    
    juce::Label tituloLabel;
    
    Reverb_MasterClassAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(reverb_HeaderGUI)
};
