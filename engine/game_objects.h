#include "raylib.h"

// #include "utils.h"

#include <string>
#include <vector>
#include <iostream>

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

        draw() {
            ClearBackground(this->color);
        }
    }

    struct ScreenBackground : AbstractObject {
        Image ** texture;
        ScreenBackground(Image * txtr) {
            this->texture = &txtr;
        };

        ~ScreenBackground() {};

        draw() {
            
        }
    };
}