#include "raylib.h"

// #include "utils.h"

#include <string>
#include <vector>
#include <iostream>

#include "structures.h"

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
        RectangleButton2D(int posX, int posY, int width, int height, Color color, std::string text = NULL) {
            this->posX = posX;
            this->posY = posY;
            this->width = width;
            this->height = height;
            this->color = color;
        }

        ~RectangleButton2D() {};
        void draw() {
            DrawRectangle(this->posX, this->posY, this->width, this->height, this->color);
        }
    };
}