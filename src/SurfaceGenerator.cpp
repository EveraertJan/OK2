//
//  SurfaceGenerator.cpp
//  OK_V2
//
//  Created by Jan Everaert on 14/05/2021.
//

#include "SurfaceGenerator.hpp"

SurfaceGenerator::SurfaceGenerator()
{
  ofEnableAlphaBlending();
  
  envSources.push_back("water");
  envSources.push_back("space");
  
  loadNewSource();
  
  
  wall_FBO.allocate(WIDTH, HEIGHT, GL_RGBA);
  ceiling_FBO.allocate(WIDTH, HEIGHT, GL_RGBA);
  
  wall_FBO.begin();
  ofClear(0, 0, 0, 0);
  wall_FBO.end();
  
  ceiling_FBO.begin();
  ofClear(0, 0, 0, 0);
  ceiling_FBO.end();
}

void SurfaceGenerator::handleOSC(ofxOscMessage msg)
{
  string a = msg.getAddress();
}

void SurfaceGenerator::update(bool INTERACTION)
{
  if(backVid.isLoaded()) {
    backVid.update();
  }
  if( midVid.isLoaded() ) {
    midVid.update();
  }
  if( interactionVid.isLoaded()) {
    interactionVid.update();
  }
  
  
  if(INTERACTION && !interactionVid.isPlaying()) {
    interactionVid.play();
  }
}
void SurfaceGenerator::generate( bool DEBUG)
{
  // // prep walls
  wall_FBO.begin();
  ofEnableAlphaBlending();
  ofClear(0, 0, 0, 0);
  
  ofSetColor(255, 255, 255, 255);
  if(backVid.isLoaded()) {
    backVid.draw(0, 0, WIDTH, HEIGHT);
  }
  if( interactionVid.isLoaded()) {
    interactionVid.draw(0, 0, WIDTH, HEIGHT);
  }
  if( midVid.isLoaded()) {
    midVid.draw(0, 0, WIDTH, HEIGHT);
  }
  
  ofDisableAlphaBlending();
  wall_FBO.end();
}

void SurfaceGenerator::draw(int drawWidth, int drawHeight, int position, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS)
{
}

void SurfaceGenerator::loadNewSource()
{
  backVid.stop();
  midVid.stop();
  interactionVid.stop();
  
  backVid.close();
  midVid.close();
  interactionVid.close();
  
  std::string pre = envSources[curSource];
  
  std::cout << pre << endl;
  
  backVid.load("video/"+pre+"/background.mp4");
  if(pre != "space") {
    midVid.load("video/"+pre+"/mid.mov");
  }
  
  interactionVid.load("video/"+pre+"/interaction.mov");
  
  
  backVid.play();
  midVid.play();
  interactionVid.play();
  interactionVid.setLoopState(OF_LOOP_NONE);
}

void SurfaceGenerator::nextSource() {
  curSource++;
  if(curSource > envSources.size()-1){
    curSource = 0;
  }
  
  std::cout << envSources[curSource] << endl;
  loadNewSource();
}


void SurfaceGenerator::prevSource() {
  curSource--;
  
  if(curSource < 0) {
    curSource = envSources.size() -1;
  }
  
  std::cout << envSources[curSource] << endl;
  loadNewSource();
}
