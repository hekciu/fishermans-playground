// TODO: ogarnij to: https://www.geeksforgeeks.org/include-guards-in-c/ zeby poprawnie zainkludowac pliki do siebie

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