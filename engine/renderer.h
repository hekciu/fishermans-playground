#include <string>

#include "structures.h"

class Renderer {
public:
	static void printMessage(const std::string &msg);
	static void initWindow();
	static void updateConfig(const Structures::RendererConfig &config);
	static void printConfig();
private:
	static Structures::RendererConfig config;
};
