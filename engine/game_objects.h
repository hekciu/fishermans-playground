#ifndef GAME_OBJECTS
#define GAME_OBJECTS

#include "raylib.h"

// #include "utils.h"

#include <string>
#include <vector>
#include <iostream>

#include "structures.h"
#include "event_manager.h"

namespace GameObjects {
    struct AbstractObject {
        bool isVisible;
        AbstractObject(){};
        virtual ~AbstractObject(){};
        virtual void draw() = 0;
    };

    struct BackgroundColor : AbstractObject {
        Color color;
        BackgroundColor(Color clr) {
            this->color = clr;
        };

        ~BackgroundColor() {};

        void draw() {
            ClearBackground(this->color);
        }
    };

    struct ScreenBackground : AbstractObject {
        Image * texture;
        ScreenBackground(Image * txtr) {
            this->texture = txtr;
        };

        ~ScreenBackground() {};

        void draw() {
            
        }
    };

    struct RectangleButton2D : AbstractObject {
        int posX;
        int posY;
        int width;
        int height;
        Color color;
        std::string text;
        int fontSize;
        Color fontColor;
        Rectangle rec;
        RectangleButton2D(int posX,
                int posY,
                int width,
                int height,
                Color color,
                std::string text = "",
                int fontSize = 0,
                Color fontColor = BLUE) {
            this->posX = posX;
            this->posY = posY;
            this->width = width;
            this->height = height;
            this->color = color;
            this->text = text;
            this->fontSize = fontSize;
            this->fontColor = fontColor;
            this->rec = {(float)this->posX, (float)this->posY, (float)this->width, (float)this->height};
        }

        ~RectangleButton2D() {};

        void draw() {
            DrawRectangle(this->posX, this->posY, this->width, this->height, this->color);
            int textPadding = (this->height - this->fontSize) / 2;
            int textPosX = this->posX + textPadding;
            int textPosY = this->posY + textPadding;
            DrawText(this->text.c_str(), textPosX, textPosY, this->fontSize, this->fontColor);

            int leftButton = 0;
            // handle being left-clicked
            const Vector2 cursorPosition = GetMousePosition();
            const bool wasMouseButtonPressed = IsMouseButtonPressed(leftButton);
            if (wasMouseButtonPressed && CheckCollisionPointRec(cursorPosition, this->rec)) {
                this->onClick();
            }
        }

        virtual void onClick() {};
    };

    struct ChangeModeRectangleButton2D : RectangleButton2D {
        std::map<int, int> modeLogic;
        ChangeModeRectangleButton2D(int posX,
                int posY,
                int width,
                int height,
                Color color,
                std::string text = "",
                int fontSize = 0,
                Color fontColor = BLUE,
                std::map<int, int> modeLogic = ): RectangleButton2D(posX, posY, width, height, color, text, fontSize, fontColor) {
            
            this->modeLogic = modeLogic;
        };
        ~ChangeModeRectangleButton2D() {};

        void onClick() {
            int currentRendererMode = 1;

            int mode = this->modeLogic[currentRendererMode];
            EventManager::AbstractEvent * = new EventManager::ChangeModeEvent(mode);

            EventManager::addEvent();
        }
    };
}

#endif