#ifndef NUI_BASE_H
#define NUI_BASE_H

#include <SDL2/SDL.h>


class Base {
    public:
        // Members [public]
        int x, y, width, height;
        bool isVisible;

        /* Constructor
         
        Other UI elements should have their members after basic members in the constructor.
        Example:

        int width,
        int height,
        int x, 
        int y,
        bool isVisible = true,
        ... <-- add other members
        */

        Base(
            int width,
            int height,
            int x, 
            int y,
            bool isVisible = true
        );

        // Destructor
        virtual ~Base();

        // Functions
        virtual void render(SDL_Renderer* renderer);
        virtual void draw();
        virtual void update();

        // Functions [setters]
        void setSize(int w, int h);
        void setPos(int x, int y);

        // Functions [getters]
        int getWidth() const;
        int getHeight() const;
        int getX() const;
        int getY() const;        
        SDL_Rect getRect() const;

    private:
        // Members [private]
        SDL_Rect rect;
};

#endif