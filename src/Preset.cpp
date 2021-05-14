#include "./Preset.hpp"

void Preset::setup(vector<ProjectionMesh> meshes)
{
  // ProjectionMesh m;
  // m.setup(
  //     100, 100,
  //     ofGetWidth() - 100, 100,
  //     ofGetWidth() - 100, ofGetHeight() - 100,
  //     100, ofGetHeight() - 100);

  currentMeshes = meshes;
}

void Preset::update()
{
}

void Preset::draw(ofFbo surface)
{
  if (currentMeshes.size() > 0)
  {
    for (int i = 0; i < currentMeshes.size(); i++)
    {
      if (DEBUG && i == curMesh)
      {
        currentMeshes[i].draw(surface, DEBUG);
      }
      else
      {
        currentMeshes[i].draw(surface, false);
      }
    }
  }
}
void Preset::handleOSC(ofxOscMessage msg)
{
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
    currentMeshes.push_back(m);
    curMesh++;
  };
  if (a == "/preset/mesh/remove")
  {
    std::cout << "remove mesh" << endl;
    if (currentMeshes.size() > 0)
    {
      currentMeshes.erase(currentMeshes.begin() + curMesh);
      curMesh--;
    }
  };

  if (a == "/preset/mesh/prev")
  {
    curMesh--;
    if (curMesh < 0)
    {
      curMesh = currentMeshes.size() - 1;
    }
    std::cout << "prev mesh" << curMesh << endl;
  };
  if (a == "/preset/mesh/next")
  {
    curMesh++;
    if (curMesh > currentMeshes.size() - 1)
    {
      curMesh = 0;
    }
    std::cout << "next mesh" << curMesh << endl;
  };
  currentMeshes[curMesh].handleOSC(msg);

  // if (a == "/keystoneV")
  // {
  //   keyStoneV = msg.getArgAsFloat(0);
  // }
  // if (a == "/keystoneH")
  // {
  //   keyStoneH = msg.getArgAsFloat(0);
  // }
}