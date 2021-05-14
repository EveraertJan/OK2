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
#include "ofxOsc.h"

#include "settings.hpp"

class SurfaceGenerator
{

public:
	SurfaceGenerator();
	void update();
	void draw(int drawWidth, int drawHeight, int position, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS);
	void loadNewSource(std::string source);
	void handleOSC(ofxOscMessage msg);

	ofSoundPlayer interactionSound;

	ofFbo wall_FBO;
	ofFbo ceiling_FBO;

	ofImage back;
	ofImage mid;
	ofImage top;

		int HEIGHT = _height;
	int WIDTH = _width;
};

#endif /* SurfaceClass_hpp */
