
#include "./ProjectionMesh.hpp"

void ProjectionMesh::setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
  ofPoint p1 = ofPoint(x1, y1);
  points.push_back(p1);
  ofPoint p2 = ofPoint(x2, y2);
  points.push_back(p2);
  ofPoint p3 = ofPoint(x3, y3);
  points.push_back(p3);
  ofPoint p4 = ofPoint(x4, y4);
  points.push_back(p4);

  ofPoint zero = ofPoint(0, 0);
  fine.push_back(zero);
  fine.push_back(zero);
  fine.push_back(zero);
  fine.push_back(zero);
}

void ProjectionMesh::draw(ofFbo surface, bool DEBUG)
{
  surface.getTexture().bind();
  glBegin(GL_TRIANGLE_STRIP);
  ofSetColor(255, 255, 0, 255);
  ofFill();
  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2f(0, 0);
  glVertex2f(points[0].x + fine[0].x, points[0].y + fine[0].y);

  glTexCoord2f(surface.getWidth(), 0);
  glVertex2f(points[1].x + fine[1].x, points[1].y + fine[1].y);

  glTexCoord2f(0, surface.getHeight());
  glVertex2f(points[3].x + fine[3].x, points[3].y + fine[3].y);

  glTexCoord2f(surface.getWidth(), surface.getHeight());
  glVertex2f(points[2].x + fine[2].x, points[2].y + fine[2].y);

  glEnd();
  surface.getTextureReference().unbind();
  ofFill();
  if (DEBUG)
  {
    for (int i = 0; i < points.size(); i++)
    {
      ofNoFill();
      if (selectedPoint == i)
      {
        ofFill();
      }
      ofDrawRectangle((points[i].x + fine[i].x) - 5, (points[i].y + fine[i].y) - 5, 10, 10);
    }
  }
  ofFill();
}

void ProjectionMesh::handleOSC(ofxOscMessage msg)
{
  string a = msg.getAddress();
  // std::cout << a << endl;

  if (a == "/surface/point/prev")
  {
    selectedPoint--;
    if (selectedPoint < 0)
    {
      selectedPoint = 3;
    }
    std::cout << "prev point" << endl;
  }
  if (a == "/surface/point/next")
  {
    selectedPoint++;
    if (selectedPoint > 3)
    {
      selectedPoint = 0;
    }
    std::cout << "next point" << endl;
  }

  if (a == "/surface/point/x/coarse")
  {
    float xc = msg.getArgAsFloat(0);
    points[selectedPoint].x = xc * coarseMulti;
    // std::cout << "x point" << endl;
  }
  if (a == "/surface/point/x/fine")
  {
    float xf = msg.getArgAsFloat(0);
    fine[selectedPoint].x = xf * fineMulti;
    // std::cout << "x point" << endl;
  }

  if (a == "/surface/point/y/coarse")
  {
    float yc = msg.getArgAsFloat(0);
    points[selectedPoint].y = yc * coarseMulti;
    // std::cout << "y point" << endl;
  }

  if (a == "/surface/point/y/fine")
  {
    float yf = msg.getArgAsFloat(0);
    fine[selectedPoint].y = yf * fineMulti;
    // std::cout << "y point" << endl;
  }
}