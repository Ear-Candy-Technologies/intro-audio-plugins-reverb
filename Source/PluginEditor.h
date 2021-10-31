#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class Reverb_MasterClassAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    Reverb_MasterClassAudioProcessorEditor (Reverb_MasterClassAudioProcessor&);
    ~Reverb_MasterClassAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    Reverb_MasterClassAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Reverb_MasterClassAudioProcessorEditor)
};
