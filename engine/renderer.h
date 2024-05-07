#ifndef RENDERER
#define RENDERER

#include <string>
#include <map>
#include <vector>
#include <queue>

#include "game_objects.h"

class Renderer {
public:
	static void printMessage(const std::string &msg);
	static void initWindow();
	static bool windowShouldClose();
	static void closeWindow();
	static void updateConfig(const Structures::RendererConfig &config);
	static void printConfig();
	static void render();
	static void updateRendererModes(const std::vector<int> &modes);
	static void changeCurrentMode(const int &mode);
	static int getCurrentMode();
	static void addObjects(const int &mode, const std::vector<GameObjects::AbstractObject * > &objects);
private:
	static Structures::RendererConfig config;
	static bool wasConfigInitialized;
	static void checkConfig();
	static void setup();
	static std::vector<int> rendererModes;
	static bool wereRendererModesInitialized;
	static std::map<int, std::vector<GameObjects::AbstractObject * >> gameObjects;
	static int currentRendererMode;
	static void isModeValid(const int &mode);
};

#endif