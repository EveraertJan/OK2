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
  void draw(ofFbo surface, bool debug);
  void handleOSC(ofxOscMessage msg);

  // ofPoint p1;
  // ofPoint p2;
  // ofPoint p3;
  // ofPoint p4;

  vector<ofPoint> points;
  vector<ofPoint> fine;

  int selectedPoint = 0;
  float coarseMulti = 20;
  float fineMulti = 1;
};

#endif /* SurfaceClass_hpp */
