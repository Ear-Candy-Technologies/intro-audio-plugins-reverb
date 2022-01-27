#include "reverb_HeaderGUI.h"

reverb_HeaderGUI::reverb_HeaderGUI(Reverb_MasterClassAudioProcessor& p) : audioProcessor(p)
{
    setSize(400, 50);
    
    createLabel();
}

reverb_HeaderGUI::~reverb_HeaderGUI(){}

void reverb_HeaderGUI::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::skyblue);
    g.fillAll();
}

void reverb_HeaderGUI::resized()
{
    tituloLabel.setBounds(getWidth()/2 - 50, 10, 100, 30);
}

void reverb_HeaderGUI::createLabel()
{
    tituloLabel.setText("REVERB", juce::dontSendNotification);
    tituloLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    tituloLabel.setFont(juce::Font(24.0f));
    tituloLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(tituloLabel);
}
