#ifndef EVENT_MANAGER
#define EVENT_MANAGER


class EventManager {
public:
    struct AbstractEvent;
    struct ChangeModeEvent;
    static void processEvents();
    static void addEvent(EventManager::AbstractEvent * event);
private:
    static std::queue<EventManager::AbstractEvent *> events;
};

#endif