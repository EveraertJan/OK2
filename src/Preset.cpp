#include "./Preset.hpp"

void Preset::setup(string h, vector<vector<ProjectionMesh>> meshes)
{
  // ProjectionMesh m;
  // m.setup(
  //     100, 100,
  //     ofGetWidth() - 100, 100,
  //     ofGetWidth() - 100, ofGetHeight() - 100,
  //     100, ofGetHeight() - 100);
  handle = h;
  currentMeshes = meshes;
}

void Preset::update()
{
}

void Preset::draw(ofFbo surface, bool DEBUG_MODE, int ORIENT)
{
	curOrient = ORIENT;
	vector<ProjectionMesh> c = currentMeshes[ORIENT];
	  if (c.size() > 0)
	  {
		for (int i = 0; i < c.size(); i++)
		{
		  if (DEBUG_MODE && i == curMesh)
		  {
			  c[i].draw(surface, DEBUG_MODE);
		  }
		  else
		  {
			c[i].draw(surface, false);
		  }
		}
	  }
}
void Preset::handleOSC(ofxOscMessage msg)
{
	vector<ProjectionMesh> *c = &currentMeshes[curOrient];
  string a = msg.getAddress();
  // std::cout << a << endl;
  
  if (a == "/preset/mesh/add")
  {
    std::cout << "adding mesh" << endl;
    ProjectionMesh m;
    m.setup(
            100, 100,
            ofGetWidth() - 100, 100,
            ofGetWidth() - 100, ofGetHeight() - 100,
            100, ofGetHeight() - 100);
    c->push_back(m);
    curMesh++;
  };
  if (a == "/preset/mesh/remove")
  {
    std::cout << "remove mesh" << endl;
    if (c->size() > 0)
    {
      c->erase(c->begin() + curMesh);
      curMesh--;
    }
  };
  
  if (a == "/preset/mesh/prev")
  {
    curMesh--;
    if (curMesh < 0)
    {
      curMesh = c->size() - 1;
    }
    std::cout << "prev mesh" << curMesh << endl;
  };
  if (a == "/preset/mesh/next")
  {
    curMesh++;
    if (curMesh > c->size() - 1)
    {
      curMesh = 0;
    }
    std::cout << "next mesh" << curMesh << endl;
  };
  c->at(curMesh).handleOSC(msg);
  
  // if (a == "/keystoneV")
  // {
  //   keyStoneV = msg.getArgAsFloat(0);
  // }
  // if (a == "/keystoneH")
  // {
  //   keyStoneH = msg.getArgAsFloat(0);
  // }
}
