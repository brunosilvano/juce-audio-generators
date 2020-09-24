/*
  ==============================================================================

    SineGenerator.h
    Created: 24 Sep 2020 10:02:04pm
    Author:  Bruno Silvano Costa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SineGenerator  : public juce::AudioSource
{
public:
  //==============================================================================
  SineGenerator();
  ~SineGenerator() override;

  //==============================================================================
  void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
  void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
  void releaseResources() override;

  //==============================================================================
  void setFrequency(double newFrequency) { currentFrequency = newFrequency; updateAngleDelta(); }
  void setLevel(double newLevel) { level = newLevel; }
  void updateAngleDelta();

private:
  //==============================================================================
  // Your private member variables go here...
  double level = 1.0f;

  double currentFrequency = 0.0f;
  double currentSampleRate = 0.0f;
  double currentAngle = 0.0f;
  double angleDelta = 0.0f;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SineGenerator)
};
