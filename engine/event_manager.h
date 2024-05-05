#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include "events.h"

class EventManager {
public:
    static void processEvents();
    static void addEvent(Events::AbstractEvent * event);
private:
    static std::queue<Events::AbstractEvent *> events;
};

#endif