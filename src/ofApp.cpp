#include "ofApp.h"

#include "settings.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
  
  sender.setup(_ip, _sendport);
  receiver.setup(_recport);
  
  presets.setup(sender);
  sound.load("sounds/back.mp3");
  sound.play();
  sound.setVolume(vol);
  sound.setLoop(true);
  
  
  std::string fSource = surfaceGenerator.envSources[surfaceGenerator.curSource];
  interactionSound.load("sounds/" + fSource + ".mp3");
  interactionSound.stop();
  interactionSound.setVolume(vol);

}

//--------------------------------------------------------------
void ofApp::update()
{
	if (DISPLAY_PROJ) {
		surfaceGenerator.update(DISPLAY_INTERACTION, DISPLAY_MASCOTTE);
		presets.update();
	}
  while (receiver.hasWaitingMessages())
  {
    ofxOscMessage msg;
    receiver.getNextMessage(&msg);
     std::cout << msg << endl;
    
    presets.handleOSC(msg);
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(0, 0, 0);
	if (DISPLAY_PROJ) {
		surfaceGenerator.generate(DEBUG_MODE, ORIENT);

		presets.draw(surfaceGenerator.wall_FBO, DEBUG_MODE, ORIENT);
	}

	if (ofGetElapsedTimeMillis() - volStart < 2000) {
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 + 20);
		ofDrawBitmapStringHighlight(ofToString(ceilf(vol * 5)), 0, 0);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  switch (key)
  {
    case '0':
      presets.currentPreset = 0;
      break;
    case '1':
      presets.prevPreset();
      break;
    case '2':
      presets.nextPreset();
      break;
    case '3':
      // open
     break;
    case '4':
    case 'l':
      DISPLAY_INTERACTION = true;
      interactionSound.play();
      interactionSound.setLoop(false);
      interactionSound.setVolume(vol);
      break;
    case '5':
    case 'i':
      // DISPLAY_INTERACTION = true;
      
      DISPLAY_MASCOTTE = true;
      break;
    case '7':
    case 'v':
      DEBUG_MODE = !DEBUG_MODE;
      break;
    case '8':
    case 'c':
      // DISPLAY_CAM = !DISPLAY_CAM;
      DISPLAY_PROJ = !DISPLAY_PROJ;
      break;
	case '-':
		vol-=soundIncr;
		if (vol <= 0) {
			vol = 0;
		}
		interactionSound.setVolume(vol);
		sound.setVolume(vol);
    overlaySound.setVolume(vol);
		volStart = ofGetElapsedTimeMillis();
	break;

	case '+':
		vol+= soundIncr;
		if (vol >= 9) {
			vol = 9;
		}
		interactionSound.setVolume(vol);
		sound.setVolume(vol);
    overlaySound.setVolume(vol);
		volStart = ofGetElapsedTimeMillis();
      break;
   
    case '.':
    case 'q':
       if (sound.isPlaying())
       {
         sound.stop();
       }
       else
       {
         sound.play();
		 sound.setLoop(true);
       }
      break;
    default:
      // std::cout << "wrong command used" << key;
      break;
  }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
  switch (key)
  {
    case 'i':
    case '5':
      surfaceGenerator.loadNewMascotte();
      DISPLAY_MASCOTTE = false;
      break;
    case 'l':
    case '4':
      // DISPLAY_LOUIS = false;
      DISPLAY_INTERACTION = false;
      break;
	case '3': {
    surfaceGenerator.nextSource();
    std::string iSource = surfaceGenerator.envSources[surfaceGenerator.curSource];
    interactionSound.load("sounds/" + iSource + ".mp3");
    if(iSource == "jungle") {
      overlaySound.load("video/"+iSource + "/music.mp3");
      overlaySound.setLoop(true);
      overlaySound.play();
    }
    interactionSound.stop();
    break;
    }
  //case '-': {
  //  surfaceGenerator.prevSource();
  //  std::string oSource = surfaceGenerator.envSources[surfaceGenerator.curSource];
  //  interactionSound.load("sounds/"+oSource+".mp3");
  //  interactionSound.stop();
  //  break;
  //}
  default:
      // std::cout << "wrong command used" << key;
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
