#include "raylib.h"

#include "utils.h"

#include <string>

namespace GameObjects {
    struct AbstractObject {
        bool isVisible;
        virtual AbstractObject(){};
        virtual ~AbstractObject(){};
    }

    struct ScreenBackground : AbstractObject {
        Image texture;
        ScreenBackground(std::string texturePath) {
            this->texture = LoadImage(texturePath.c_str());

            while(!IsImageReady(this->texture)) {
                engineSleep(1);
            };
        };

        ~ScreenBackground() {

        };
    }
}