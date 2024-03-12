#include "renderer.h"


class Renderer {
	static Renderer * instance;
	
	public:
	Renderer() {
		
	}

	~Renderer() {
		
	}

	static Renderer * getInstance() {
		if (Renderer::instance == nullptr) {
			Renderer::instance = new Renderer();
		}
		
		return Renderer::instance;
		
	}
};
