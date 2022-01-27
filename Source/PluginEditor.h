#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "reverb_HeaderGUI.h"
#include "reverb_MainGUI.h"

class Reverb_MasterClassAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    Reverb_MasterClassAudioProcessorEditor (Reverb_MasterClassAudioProcessor&);
    ~Reverb_MasterClassAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    reverb_HeaderGUI header;
    
    reverb_MainGUI main;
    
    Reverb_MasterClassAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Reverb_MasterClassAudioProcessorEditor)
};
