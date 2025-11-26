#ifndef UI_LABEL_H
#define UI_LABEL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <globals.h>
#include <settings.h>

#include <ui/base.h>
#include <string>

class Label : public Base {
    public: 
        // Members [public]
        SDL_Color textColor;
        SDL_Color backColor;

        // Constructor
        Label(
            int width,
            int height,
            int x,
            int y,
            bool isVisible,
            const std::string& text,
            SDL_Color textColor,
            SDL_Color backColor
        );

        // Destructor
        ~Label() override;

        // Functions
        void render(SDL_Renderer* renderer) override;
        void draw() override;
        void update() override;

        // Functions [setters]
        void setText(const std::string& newText);
        std::string getText() const;
        void setTextWrap(bool wrap);

        void setColor(const SDL_Color& textColor, const SDL_Color& backColor);
        void setTextColor(const SDL_Color& color);
        void setBackColor(const SDL_Color& color);

        // Functions [getters]
        bool getTextWrap() const;

    private:
        // Members [private]
        std::string text;
        bool isWrapped;

        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;
        TTF_Font* font;
};

#endif