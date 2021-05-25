//
//  SurfaceGenerator.cpp
//  OK_V2
//
//  Created by Jan Everaert on 14/05/2021.
//

#ifndef SurfaceClass_hpp
#define SurfaceClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxHapPlayer.h"
#include "ofxOsc.h"

#include "settings.hpp"

class SurfaceGenerator
{
  
public:
  SurfaceGenerator();
  void update(bool INTERACTION);
  void generate(bool DEBUG_MODE, int ORIENT);
  void draw(int drawWidth, int drawHeight, int position, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS);
  void loadNewSource();
  void handleOSC(ofxOscMessage msg);
  
  void nextSource();
  void prevSource();
  
  ofSoundPlayer interactionSound;
  
  ofFbo wall_FBO;
  ofFbo ceiling_FBO;
  
  int HEIGHT = _height;
  int WIDTH = _width;
  
  vector<std::string> envSources;
  int curSource = 1;
  
  ofxHapPlayer backVid;
  ofxHapPlayer interactionVid;
  ofxHapPlayer midVid;

  int currentOrient = 0;
  
};

#endif /* SurfaceClass_hpp */
