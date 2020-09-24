/*
  ==============================================================================

    SineGenerator.cpp
    Created: 24 Sep 2020 10:02:04pm
    Author:  Bruno Silvano Costa

  ==============================================================================
*/

#include "SineGenerator.h"

SineGenerator::SineGenerator()
{

}

SineGenerator::~SineGenerator()
{

}

void SineGenerator::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
  currentSampleRate = sampleRate;
  updateAngleDelta();
}

void SineGenerator::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill)
{
  auto* leftBuffer  = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
  auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

  for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
  {
    auto currentSample = (float) std::sin(currentAngle);
    currentAngle += angleDelta;
    leftBuffer[sample] = currentSample * level;
    rightBuffer[sample] = currentSample * level;
  }
}

void SineGenerator::releaseResources()
{

}

void SineGenerator::updateAngleDelta()
{
  const auto cyclesPerSample = currentFrequency / currentSampleRate;
  angleDelta = cyclesPerSample * 2.0f * juce::MathConstants<double>::pi;
}
