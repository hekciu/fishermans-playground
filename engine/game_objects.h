#include "raylib.h"

// #include "utils.h"

#include <string>
#include <vector>
#include <iostream>

#include "enums.h"

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

    struct Button2D : AbstractObject {
        Enums::ButtonType type;
        Button2D(const Enums::ButtonType &tp) {
            this->type = tp;
        }

        ~Button2D() {};

        void draw() {

        }
    };
}