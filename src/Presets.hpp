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
  void setup();

  void update();

  void draw(ofFbo surface);

  void handleOSC(ofxOscMessage msg);

  void saveSettings();
  void loadSettings();

  int currentPreset;
  vector<Preset> presets;

  bool DEBUG = true;
};

#endif /* PresetClass_hpp */
