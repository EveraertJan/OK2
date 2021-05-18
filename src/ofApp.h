#pragma once

#include "ofMain.h"
#include "SurfaceGenerator.hpp"
#include "ofxOsc.h"
#include "Presets.hpp"

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
  
  SurfaceGenerator *surfaceGenerator;
  
  Presets presets;
  
  bool DISPLAY_MASCOTTE = false;
  bool DISPLAY_INTERACTION = false;
  bool DEBUG_MODE = false;
};
