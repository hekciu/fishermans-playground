#include <queue>

#include "event_manager.h"
#include "renderer.h"

/* defining basic static members */

std::queue<EventManager::AbstractEvent *> EventManager::events;

/* defining events */

struct EventManager::AbstractEvent {
    AbstractEvent(){};
    virtual ~AbstractEvent(){};
    virtual void performAction() = 0;
};

struct EventManager::ChangeModeEvent : EventManager::AbstractEvent {
    int mode;
    ChangeModeEvent(int mode) {
        this->mode = mode;
    }
    ~ChangeModeEvent() {};
    void performAction() {
        Renderer::changeCurrentMode(this->mode);
    };
};

/* defining static methods */

void EventManager::processEvents() {
	while (EventManager::events.size() != 0) {
		EventManager::AbstractEvent * event = EventManager::events.front();
		event->performAction();
		delete event;
		EventManager::events.pop();
	}
}

void EventManager::addEvent(EventManager::AbstractEvent * event) {
    EventManager::events.push(event);
}