#include "ofApp.h"

#include "settings.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
  
  sender.setup(_ip, _sendport);
  receiver.setup(_recport);
  
  
  presets.setup(sender);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (DISPLAY_PROJ) {
		surfaceGenerator.update(DISPLAY_INTERACTION);
		presets.update();
	}
  while (receiver.hasWaitingMessages())
  {
    ofxOscMessage msg;
    receiver.getNextMessage(&msg);
    // std::cout << msg << endl;
    
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
		ORIENT++;
		if (ORIENT == 2) {
			ORIENT = 0;
		}
      break;
    case '4':
    case 'l':
      DISPLAY_MASCOTTE = true;
      DISPLAY_INTERACTION = true;
      break;
    case '5':
    case 'i':
      // DISPLAY_INTERACTION = true;
      break;
    case '7':
    case 'v':
      DEBUG_MODE = !DEBUG_MODE;
      break;
    case '8':
    case 'c':
      // DISPLAY_CAM = !DISPLAY_CAM;
      break;
    case '9':
    case 'm':
      // MUTE = !MUTE;
	  // if (MUTE)
      // {
      //   sound.setVolume(0);
      // }
      // else
      // {
      //   sound.setVolume(5);
      // }
		DISPLAY_PROJ = !DISPLAY_PROJ;
      break;
    case '+':
    case 'w':
      surfaceGenerator.nextSource();
      break;
    case '-':
    case 's':
      surfaceGenerator.prevSource();
      break;
    case '.':
      // if (sound.isPlaying())
      // {
      //   sound.stop();
      // }
      // else
      // {
      //   sound.play();
      // }
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
      // DISPLAY_INTERACTION = false;
      break;
    case 'l':
    case '4':
      // DISPLAY_LOUIS = false;
      DISPLAY_INTERACTION = false;
      break;
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
