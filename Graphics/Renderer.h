#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include <string>
#include <queue>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Drawer.h"
#include "../Utils/bbox.h"
#include "../Utils/vec.h"
#include "../Utils/Comparer.h"
#include "../Utils/Math.h"

namespace jr
{

using std::priority_queue;
using std::vector;
using Utils::vec;
using Utils::bbox;

class Renderer
{
  friend class Drawer;

	public:
		Renderer(int width, int height, std::string title);
		~Renderer();

    bool isWindowOpen();
    void pollEvents();
    void updateBounds(bbox<float> newBounds);
    void draw(sf::Drawable* img, int priority);
    void render();
    
  private:

    class DrawObject{
      public:
        DrawObject(sf::Drawable* i, int p);
        sf::Drawable* image;
        int priority;
    };

    class DrawObjectComparer : public Comparer {
      public:
        virtual bool operator()(void* a, void* b);
    };


    sf::RenderWindow* window;
    priority_queue<DrawObject*,
                   vector<DrawObject*>,
                   DrawObjectComparer> drawQueue;
    bbox<int> pixelBounds;
    int PIXELS_PER_METER;

    int pixelConvert(float real);
    int pixelConvertX(float realX);
    int pixelConvertY(float realY);
};

}
#endif
