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
  void setup(string h, vector<vector<ProjectionMesh>> meshes);
  void update();
  void draw(ofFbo surface, bool DEBUG_MODE, int ORIENT);
  void handleOSC(ofxOscMessage msg);


  vector<vector<ProjectionMesh>> currentMeshes;
 

  int curMesh = 0;

  int curOrient = 0;
  string handle = handle;
};

#endif /* SurfaceClass_hpp */
