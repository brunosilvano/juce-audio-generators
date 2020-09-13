/*
  ==============================================================================

    NoiseGenerator.cpp
    Created: 13 Sep 2020 7:34:01pm
    Author:  Bruno Silvano Costa

  ==============================================================================
*/

#include "NoiseGenerator.h"

NoiseGenerator::NoiseGenerator()
{

}

NoiseGenerator::~NoiseGenerator()
{

}

void NoiseGenerator::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{

}

void NoiseGenerator::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill)
{
  for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
  {
    auto* buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);

    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
    {
      buffer[sample] = random.nextFloat() * 0.25f - 0.125f;
    }
  }
}

void NoiseGenerator::releaseResources()
{

}
