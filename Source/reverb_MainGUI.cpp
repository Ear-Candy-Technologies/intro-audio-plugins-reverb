#include "reverb_MainGUI.h"

reverb_MainGUI::reverb_MainGUI(Reverb_MasterClassAudioProcessor& p) : audioProcessor(p)
{
    setSize(400, 250);
    
    createSlider();
    createButton();
    
    getLookAndFeel().setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    getLookAndFeel().setColour(juce::TextButton::buttonColourId, juce::Colours::red);
}

reverb_MainGUI::~reverb_MainGUI()
{
    setLookAndFeel(nullptr);
}

void reverb_MainGUI::paint(juce::Graphics& g)
{
    
}

void reverb_MainGUI::resized()
{
    timeSlider.setBounds(20, 20, 80, 80);
    mixSlider.setBounds(140, 50, 120, 20);
    preDelaySlider.setBounds(300, 10, 80, 150);
    reverbButton.setBounds(165, 160, 80, 40);
}

void reverb_MainGUI::createSlider()
{
    timeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    timeSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    timeSlider.setPopupDisplayEnabled(true, true, this);
    timeSlider.setTextValueSuffix(" s");
    timeSlider.setDoubleClickReturnValue(true, 1.0);
    timeSlider.setLookAndFeel(&sliderFront);
    addAndMakeVisible(timeSlider);
    
    timeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.parameters,
                                                                                                  REV_TIME_ID,
                                                                                                  timeSlider);
    
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::LinearBar);
    mixSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 50, 20);
    mixSlider.setPopupDisplayEnabled(true, true, this);
    mixSlider.setTextValueSuffix(" %");
    mixSlider.setDoubleClickReturnValue(true, 1.0);
    addAndMakeVisible(mixSlider);
    
    mixSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.parameters,
                                                                                                 REV_MIX_ID,
                                                                                                 mixSlider);
    
    preDelaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    preDelaySlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 20);
    preDelaySlider.setPopupDisplayEnabled(true, true, this);
    preDelaySlider.setTextValueSuffix(" ms");
    preDelaySlider.setDoubleClickReturnValue(true, 1.0);
    addAndMakeVisible(preDelaySlider);
    
    preDelaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.parameters,
                                                                                                      PRE_DELAY_ID,
                                                                                                      preDelaySlider);
}

void reverb_MainGUI::createButton()
{
    reverbButton.setClickingTogglesState(true);
    reverbButton.setButtonText("On/Off");
    addAndMakeVisible(reverbButton);
    
    reverbButtonAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.parameters,
                                                                                                    REV_BUTTON_ID,
                                                                                                    reverbButton);
}

