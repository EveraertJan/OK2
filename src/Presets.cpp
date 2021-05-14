#include "./Presets.hpp"

void Presets::setup(ofxOscSender s)
{
  sender = s;
  // setup cur presets and load all
  loadSettings();

  std::cout << "done" << endl;
  std::cout << presets.size() << endl;
}

void Presets::update()
{
  // update cur preset
  // presets[currentPreset].update();
}

void Presets::draw(ofFbo surface)
{
  // draw cur preset
  if (presets.size() > 0)
  {
    presets[currentPreset].draw(surface);
  }
}
void Presets::saveSettings()
{
  ofxXmlSettings settings;
  settings.addTag("presets");
  settings.pushTag("presets");
  for (int h = 0; h < presets.size(); h++)
  {
    settings.addTag("preset");
    settings.pushTag("preset", h);

    Preset p = presets[h];

    for (int i = 0; i < p.currentMeshes.size(); i++)
    {

      settings.addTag("mesh");
      settings.pushTag("mesh", i);

      for (int j = 0; j < p.currentMeshes[i].points.size(); j++)
      {
        settings.addTag("point");
        settings.pushTag("point", j);
        settings.addValue("index", j);
        settings.addValue("x", p.currentMeshes[i].points[j].x + p.currentMeshes[i].fine[j].x);
        settings.addValue("y", p.currentMeshes[i].points[j].y + p.currentMeshes[i].fine[j].y);

        settings.popTag();
      }
      settings.addValue("imgX", p.currentMeshes[i].imageX);
      settings.addValue("imgY", p.currentMeshes[i].imageY);
      settings.addValue("imgW", p.currentMeshes[i].imageW);
      settings.addValue("imgH", p.currentMeshes[i].imageH);
      settings.popTag();
    }
    settings.popTag();
  }
  settings.popTag();
  settings.saveFile("presets.xml");
}
void Presets::createNew()
{
  std::cout << "no file, creating new" << endl;
  vector<ProjectionMesh> meshes;
  ProjectionMesh m;
  m.setup(
      100, 100,
      ofGetWidth() - 100, 100,
      ofGetWidth() - 100, ofGetHeight() - 100,
      100, ofGetHeight() - 100);

  meshes.push_back(m);

  Preset p;

  p.setup(meshes);
  presets.push_back(p);
}
void Presets::loadSettings()
{
  ofxXmlSettings settings;
  if (settings.loadFile("presets.xml"))
  {
    settings.pushTag("presets");
    vector<Preset> presetsTemp;

    int numPresets = settings.getNumTags("preset");
    for (int i = 0; i < numPresets; i++)
    {
      settings.pushTag("preset", i);
      Preset p;
      vector<ProjectionMesh> meshes;

      int numMeshes = settings.getNumTags("mesh");
      for (int j = 0; j < numMeshes; j++)
      {
        settings.pushTag("mesh", j);
        ProjectionMesh m;

        int numPoints = settings.getNumTags("point");
        for (int k = 0; k < numPoints; k++)
        {
          settings.pushTag("point", k);
          ofPoint po;
          po.x = settings.getValue("x", 0);
          po.y = settings.getValue("y", 0);

          std::cout << "pushing back points" << endl;
          m.points.push_back(po);
          m.fine.push_back(ofPoint(0, 0));
          settings.popTag();
        }
        m.imageX = settings.getValue("imgX", 0);
        m.imageY = settings.getValue("imgY", 0);
        m.imageW = settings.getValue("imgW", 0);
        m.imageH = settings.getValue("imgH", 0);

        std::cout << "pushing back meshes" << endl;
        meshes.push_back(m);
        settings.popTag();
      }
      p.setup(meshes);
      std::cout << "pushing back preset" << endl;
      presetsTemp.push_back(p);
      settings.popTag();
    }

    std::cout << "pushing back presets" << endl;
    settings.popTag();
    presets = presetsTemp;
  }
  else
  {
    std::cout << "no file, creating new" << endl;
    createNew();
    currentPreset = 0;
  }
}
void Presets::handleOSC(ofxOscMessage msg)
{
  string a = msg.getAddress();
  // std::cout << a << endl;

  if (a == "/preset/save")
  {
    std::cout << "saving" << endl;
    saveSettings();
  }

  if (a == "/preset/reset")
  {
    std::cout << "resetting" << endl;
  }

  if (a == "/presets/next")
  {
    nextPreset();
    std::cout << "next" << endl;
  }

  if (a == "/preset/previous")
  {
    prevPreset();
    std::cout << "prev" << endl;
  }

  if (a == "/presets/create")
  {
    std::cout << "creating" << endl;
    createNew();
    currentPreset = presets.size() - 1;
  }

  if (a == "/presets/delete")
  {
    std::cout << "creating" << endl;
    presets.erase(presets.begin() + currentPreset);

    currentPreset = presets.size() - 1;
  }

  presets[currentPreset].handleOSC(msg);
}

void Presets::nextPreset()
{
  sendMessage("/presets/label", currentPreset);
  currentPreset++;
  if (currentPreset >= presets.size())
  {
    currentPreset = 0;
  }
}
void Presets::prevPreset()
{
  sendMessage("/presets/label", currentPreset);
  currentPreset--;
  if (currentPreset < 0)
  {
    currentPreset = presets.size() - 1;
  }
}

void Presets::sendMessage(string channel, int value)
{
  ofxOscMessage msg;
  msg.setAddress(channel);
  msg.addFloatArg(value);
  sender.sendMessage(msg);
}