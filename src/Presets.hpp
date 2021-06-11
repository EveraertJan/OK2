//
//  PresetsClass.cpp
//  OK_V2
//
//  Created by Jan Everaert on 14/05/2021.
//

#ifndef PresetsClass_hpp
#define PresetsClass_hpp

#include <stdio.h>
#include "ofMain.h"

#include "ofxXmlSettings.h"
#include "ofxOsc.h"

#include "Preset.hpp"
#include "settings.hpp"

class Presets
{
  
public:
  void setup(ofxOscSender s);
  
  void update();
  
  void draw(ofFbo surface, bool DEBUG_MODE, int ORIENT);
  
  void handleOSC(ofxOscMessage msg);
  void createNew();
  void saveSettings();
  void loadSettings();
  
  void prevPreset();
  void nextPreset();
  
  void sendMessage(string channel, int value);
  
  ofxOscSender sender;
  
  int currentPreset;
  vector<Preset> presets;
  
  
  int startTime = 0;
};

#endif /* PresetClass_hpp */
