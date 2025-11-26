#include <ui/label.h>

// Constructor
Label::Label(
    int width,
    int height,
    int x,
    int y,
    bool isVisible,
    const std::string& text,
    SDL_Color textColor,
    SDL_Color backColor
) : Base(width, height, x, y, isVisible),
    text(text),                              
    textColor(textColor),
    backColor(backColor),
    isWrapped(false)                       
{}

// Destructor
Label::~Label() {
    if (surface) {
        SDL_FreeSurface(surface);
    }

    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

// Functions
void Label::render(SDL_Renderer* renderer) {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    surface = TTF_RenderText_Shaded(
        gFont,
        text.c_str(),
        textColor,
        backColor
    );

    if (!surface) {
        SDL_Log("Failed to create surface: %s", TTF_GetError());
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    setSize(surface->w, surface->h); 
    SDL_FreeSurface(surface);
    surface = nullptr;
}

void Label::draw() {
    if (texture && isVisible) {
        SDL_Rect destRect = { getX(), getY(), getWidth(), getHeight() };
        SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    }
}

void Label::update() {

}

// Functions [setters]
void Label::setText(const std::string& newText) {
    text = newText;
}

void Label::setTextWrap(bool wrap) {
    isWrapped = wrap;
}

void Label::setColor(const SDL_Color& textColor, const SDL_Color& backColor) {
    this->textColor = textColor;
    this->backColor = backColor;
}

void Label::setTextColor(const SDL_Color& color) {
    textColor = color;
}

void Label::setBackColor(const SDL_Color& color) {
    backColor = color;
}

// Functions [getters]
bool Label::getTextWrap() const {
    return isWrapped;
}

std::string Label::getText() const {
    return text;
}


