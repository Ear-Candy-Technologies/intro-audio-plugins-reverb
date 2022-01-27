#include "PluginProcessor.h"
#include "PluginEditor.h"

Reverb_MasterClassAudioProcessorEditor::Reverb_MasterClassAudioProcessorEditor (Reverb_MasterClassAudioProcessor& p)
    : AudioProcessorEditor (&p), header(p), main(p), audioProcessor (p)
{
    setSize (400, 300);
    
    addAndMakeVisible(header);
    addAndMakeVisible(main);
}

Reverb_MasterClassAudioProcessorEditor::~Reverb_MasterClassAudioProcessorEditor(){}

void Reverb_MasterClassAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::lightblue);
    g.fillAll();
}

void Reverb_MasterClassAudioProcessorEditor::resized()
{
    header.setBounds(0, 0, 400, 50);
    main.setBounds(0, 50, 400, 250);
}
