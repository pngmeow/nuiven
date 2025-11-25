#include "base.h"

// Constructor
Base::Base (
    int width,
    int height,
    int x, 
    int y,
    bool isVisible
) : width(width), height(height), x(x), y(y), isVisible(isVisible) {}

// Functions
Base::~Base() {}
void Base::render() {} 
void Base::update() {}

// Functions [setters]
void Base::setSize(int w, int h) {
    width = w;
    height = h;
}

void Base::setPos(int xpos, int ypos) {
    x = xpos;
    y = ypos;
}

// Functions [getters]
int Base::getWidth() const { return width; }
int Base::getHeight() const { return height; }
int Base::getX() const { return x; }
int Base::getY() const { return y; }