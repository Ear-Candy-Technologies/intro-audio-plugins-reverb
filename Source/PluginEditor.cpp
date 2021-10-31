#include "PluginProcessor.h"
#include "PluginEditor.h"

Reverb_MasterClassAudioProcessorEditor::Reverb_MasterClassAudioProcessorEditor (Reverb_MasterClassAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

Reverb_MasterClassAudioProcessorEditor::~Reverb_MasterClassAudioProcessorEditor(){}

void Reverb_MasterClassAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Reverb_MasterClassAudioProcessorEditor::resized(){}
