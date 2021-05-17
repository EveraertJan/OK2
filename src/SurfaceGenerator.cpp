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

void SurfaceGenerator::update()
{

//  if (ofGetElapsedTimeMillis() % 2)
//  {
//    indexBack++;
//    if (indexBack > back.pages.size() - 1)
//      indexBack = 0;
//
//    indexMid++;
//    if (indexMid > mid.pages.size() - 1)
//      indexMid = 0;
//  }
}
void SurfaceGenerator::generate( bool DEBUG)
{
  // // prep walls
  wall_FBO.begin();
  ofEnableAlphaBlending();
  ofClear(0, 0, 0, 0);

  ofSetColor(255, 255, 255, 255);
    
   ofImage backImg = back;
   ofPixels bp = backImg.getPixels();
   backImg.setFromPixels(bp);
   backImg.draw(0, 0, WIDTH, HEIGHT);

//  back.draw(0, 0, WIDTH, HEIGHT);
    mid.draw(0, 0, WIDTH, HEIGHT);
  ofDisableAlphaBlending();
  wall_FBO.end();
}

void SurfaceGenerator::draw(int drawWidth, int drawHeight, int position, int subX, int subY, int subWidth, int subHeight, bool INTERACTION, bool LOUIS)
{
  // back.draw(0, 0);
  //   if (INTERACTION)
  //   {
  //     if (!wall_interaction.isPlaying())
  //     {
  //       wall_interaction.play();
  //     }

  //     if (!ceiling_interaction.isPlaying())
  //     {
  //       ceiling_interaction.play();
  //     }
  //     if (interactionSound.isLoaded())
  //     {
  //       interactionSound.play();
  //     }
  //   }

  //   if (LOUIS)
  //   {
  //     int select = floor((ofGetFrameNum() / 24 / 2) % 3);

  //     if (select == 0)
  //     {
  //       louis_bottom.play();
  //     }
  //     if (select == 1)
  //     {
  //       louis_top.play();
  //     }
  //     if (select == 2)
  //     {
  //       louis_left.play();
  //     }
  //   }

  // this is a problematic thing
  if (position == 0)
  {
    wall_FBO.getTexture().drawSubsection(0, 0, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
  }

  else
  {

    ceiling_FBO.getTexture().drawSubsection(0, 0, drawWidth, drawHeight, subX, subY, subWidth, subHeight);
  }
}

void SurfaceGenerator::loadNewSource()
{
    std::string pre = envSources[curSource];
  back.load(pre+"/background.png");
  mid.load(pre+"/mid.png");
    
//    midImage
}

void SurfaceGenerator::nextSource() {
    curSource++;
    if(curSource >= envSources.size()){
        curSource = 0;
    }
    loadNewSource();
}


void SurfaceGenerator::prevSource() {
    curSource--;
    if(curSource < 0) {
        curSource = envSources.size() -1;
    }
    loadNewSource();
}
