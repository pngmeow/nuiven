#ifndef NUI_BASE_H
#define NUI_BASE_H

class Base {
    public:
        // Members
        int width, height;
        int x, y;
        bool isVisible;

        // Constructor
        Base(
            int width,
            int height,
            int x, 
            int y,
            bool isVisible = true
        );

        // Functions
        virtual ~Base();
        virtual void render();
        virtual void update();

        // Functions [setters]
        void setSize(int w, int h);
        void setPos(int x, int y);

        // Functions [getters]
        int getWidth() const;
        int getHeight() const;
        int getX() const;
        int getY() const;        
};

#endif