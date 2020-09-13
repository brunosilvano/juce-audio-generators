/*
  ==============================================================================

    NoiseGenerator.h
    Created: 13 Sep 2020 7:34:01pm
    Author:  Bruno Silvano Costa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class NoiseGenerator  : public juce::AudioSource
{
public:
  //==============================================================================
  NoiseGenerator();
  ~NoiseGenerator() override;

  //==============================================================================
  void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
  void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
  void releaseResources() override;

private:
  //==============================================================================
  // Your private member variables go here...
  juce::Random random;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseGenerator)
};
