/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <iostream>
#include <memory>

#include <JuceHeader.h>
#include "NoiseGenerator.h"
#include "SineGenerator.h"

//==============================================================================
int main (int argc, char* argv[])
{
  // Initialize device manager
  juce::AudioDeviceManager deviceManager;
  deviceManager.initialiseWithDefaultDevices(0, 2);

  // Create a noise generator source
  auto source = std::make_unique<SineGenerator>();

  // Create a player to stream audio from source
  auto player = std::make_unique<juce::AudioSourcePlayer>();
  player->setSource(source.get());

  // Attach player to output device
  deviceManager.addAudioCallback(player.get());

  // Runs indefinitely
  double level;
  double frequency;
  while(1){
    std::cin >> level >> frequency;
    source->setLevel(level);
    source->setFrequency(frequency);
  }

  return 0;
}
