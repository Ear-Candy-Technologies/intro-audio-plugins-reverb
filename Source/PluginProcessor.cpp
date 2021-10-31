#include "PluginProcessor.h"
#include "PluginEditor.h"

Reverb_MasterClassAudioProcessor::Reverb_MasterClassAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr, juce::Identifier("PARAMETERS"), initializeGUI())
#endif
{
}

Reverb_MasterClassAudioProcessor::~Reverb_MasterClassAudioProcessor(){}

juce::AudioProcessorValueTreeState::ParameterLayout Reverb_MasterClassAudioProcessor::initializeGUI()
{
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    
    //VOLUMEN SLIDER
    params.push_back(std::make_unique<juce::AudioParameterFloat>(REV_MIX_ID,
                                                                 REV_MIX_NAME,
                                                                 0.0f,
                                                                 1.0f,
                                                                 0.0f));
    
    //VOLUMEN SLIDER
    params.push_back(std::make_unique<juce::AudioParameterFloat>(REV_TIME_ID,
                                                                 REV_TIME_NAME,
                                                                 0.0f,
                                                                 1.0f,
                                                                 0.0f));
    
    //VOLUMEN SLIDER
    params.push_back(std::make_unique<juce::AudioParameterFloat>(PRE_DELAY_ID,
                                                                 PRE_DELAY_NAME,
                                                                 0.0f,
                                                                 1.0f,
                                                                 0.0f));
    
    return {params.begin(),params.end()};
}

const juce::String Reverb_MasterClassAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Reverb_MasterClassAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Reverb_MasterClassAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Reverb_MasterClassAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Reverb_MasterClassAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Reverb_MasterClassAudioProcessor::getNumPrograms()
{
    return 1;
}

int Reverb_MasterClassAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Reverb_MasterClassAudioProcessor::setCurrentProgram (int index){}

const juce::String Reverb_MasterClassAudioProcessor::getProgramName (int index)
{
    return {};
}

void Reverb_MasterClassAudioProcessor::changeProgramName (int index, const juce::String& newName){}

void Reverb_MasterClassAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock){}

void Reverb_MasterClassAudioProcessor::releaseResources(){}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Reverb_MasterClassAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Reverb_MasterClassAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

    }
}

bool Reverb_MasterClassAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* Reverb_MasterClassAudioProcessor::createEditor()
{
    return new Reverb_MasterClassAudioProcessorEditor (*this);
}

void Reverb_MasterClassAudioProcessor::getStateInformation (juce::MemoryBlock& destData){}

void Reverb_MasterClassAudioProcessor::setStateInformation (const void* data, int sizeInBytes){}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Reverb_MasterClassAudioProcessor();
}
