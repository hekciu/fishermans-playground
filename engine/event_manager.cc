#include "event_manager.h"
#include "events.h"

/* defining static members */

std::queue<Events::AbstractEvent *> EventManager::events;

/* defining static methods */

void EventManager::processEvents() {
	while (EventManager::events.size() != 0) {
		Events::AbstractEvent * event = EventManager::events.front();
		event->performAction();
		delete event;
		EventManager::events.pop();
	}
}

void EventManager::addEvent(Events::AbstractEvent * event) {
    EventManager::events.push(event);
}