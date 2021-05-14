//
//  PresetClass.cpp
//  OK_V2
//
//  Created by Jan Everaert on 14/05/2021.
//

#ifndef PresetClass_hpp
#define PresetClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxOsc.h"

#include "SurfaceGenerator.hpp"
#include "ProjectionMesh.hpp"
#include "settings.hpp"

class Preset
{

public:
  void setup(vector<ProjectionMesh> meshes);
  void update();
  void draw(ofFbo surface);
  void handleOSC(ofxOscMessage msg);

  vector<ProjectionMesh> currentMeshes;

  int curMesh = 0;

  bool DEBUG = true;
};

#endif /* SurfaceClass_hpp */
