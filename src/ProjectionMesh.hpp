//
//  ProjectionMesh.cpp
//  OK_V2
//
//  Created by Jan Everaert on 14/05/2021.
//

#ifndef MeshClass_hpp
#define MeshClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"

class ProjectionMesh
{
  
public:
  void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
  void update();
  void draw(ofFbo surface, bool DEBUG_MODE);
  void handleOSC(ofxOscMessage msg);
  
  // ofPoint p1;
  // ofPoint p2;
  // ofPoint p3;
  // ofPoint p4;
  
  vector<ofPoint> points;
  vector<ofPoint> fine;
  
  int imageW = 1;
  int imageH = 1;
  int baseW = 1024;
  int baseH = 630;
  int imageX = 0;
  int imageY = 0;
  
  int selectedPoint = 0;
  float coarseMulti = 20;
  float fineMulti = 1;
};

#endif /* SurfaceClass_hpp */
