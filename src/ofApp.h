#pragma once

#include "ofMain.h"
#include "SurfaceGenerator.hpp"
#include "ofxOsc.h"
#include "Presets.hpp"
#include "settings.hpp"

class ofApp : public ofBaseApp
{
  
public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
  ofxOscSender sender;
  ofxOscReceiver receiver;
  
  SurfaceGenerator surfaceGenerator;
  
  ofSoundPlayer sound;
  ofSoundPlayer interactionSound;
  ofSoundPlayer overlaySound;
  
  Presets presets;

  bool DISPLAY_PROJ = true;
  bool DISPLAY_MASCOTTE = false;
  bool DISPLAY_INTERACTION = false;
  bool DEBUG_MODE = false;
  bool MUTE = false;

  float vol = 2;
  float soundIncr = 0.2;
  int volStart = 0;

  int ORIENT = WALL;
};
