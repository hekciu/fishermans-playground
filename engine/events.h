#ifndef EVENTS
#define EVENTS

#include "renderer.h"

namespace Events {
    struct AbstractEvent {
        AbstractEvent(){};
        virtual ~AbstractEvent(){};
        virtual void performAction() = 0;
    };

    struct ChangeModeEvent : AbstractEvent {
        int mode;
        ChangeModeEvent(int mode) {
            this->mode = mode;
        }
        ~ChangeModeEvent() {};
        void performAction() {
            Renderer::changeCurrentMode(this->mode);
        };
    };
}

#endif