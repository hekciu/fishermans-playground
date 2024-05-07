Current goals:
- Fix the one below using callback functions in game objects
- Fix issue with recursion - both game_objects and events are needed
- Rewrite all ordinary pointers to smart pointers
- Utils depending on target (windows/linux)
- Basic events processing
- Create basic window with background and fullscreen options
- <DONE> Fix issue with linking raylib.h (linking raymath works :)
- <DONE> Why do I need to call 'make clean' two times to delete engine/*.o files?
- <DONE> Overall setup for windows
- <DONE> Integrate MinGW for windows compilation
- <DONE> Link Raylib with renderer

Principles:
- Raylib should be only used inside 'engine' abstraction layer
