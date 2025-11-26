#include "base.h"


// Constructor
Base::Base (
    int width,
    int height,
    int x, 
    int y,
    bool isVisible
) : width(width), height(height), x(x), y(y), isVisible(isVisible) {}

// Destructor
Base::~Base() {}

void Base::render(SDL_Renderer* renderer) {}
void Base::draw() {} 
void Base::update() {}

// Functions [setters]
void Base::setSize(int w, int h) {
    rect.w = w;
    rect.h = h;
}

void Base::setPos(int xpos, int ypos) {
    rect.x = xpos;
    rect.y = ypos;
}

// Functions [getters]
int Base::getWidth() const { return rect.w; }
int Base::getHeight() const { return rect.h; }
int Base::getX() const { return rect.x; }
int Base::getY() const { return rect.y; }
SDL_Rect Base::getRect() const { return rect; }