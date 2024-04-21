#include <string>

#include "enums.h"

namespace Structures {
    struct RendererConfig {
		int initialWindowWidth;
		int initialWindowHeight;
		bool windowShouldScale;
		std::string windowName;
		int targetFPS;
	};

	struct RendererEventMessage {
		Enums::RendererEventMessageType type;
		arguments ?? TODO
	};
};