Current goals:
- Another include loop error -> Renderer needed in game_objects
- Renderer mode changing on button pressed
- Event state in event renderer
- Rewrite all ordinary pointers to smart pointers
- Utils depending on target (windows/linux)
- Create basic window with background and fullscreen options
- <ABANDONED - NOT NEEDED> Fix the one below using callback functions in game objects
- <DONE> Basic events processing
- <DONE> Fix issue with recursion - both game_objects and events are needed
- <DONE> Fix issue with linking raylib.h (linking raymath works :)
- <DONE> Why do I need to call 'make clean' two times to delete engine/*.o files?
- <DONE> Overall setup for windows
- <DONE> Integrate MinGW for windows compilation
- <DONE> Link Raylib with renderer

Principles:
- Raylib should be only used inside 'engine' abstraction layer
