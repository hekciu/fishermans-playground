


class Renderer {
	static Renderer * instance = nullptr;

	Renderer() {
		
	}

	~Renderer() {
		
	}

	static Renderer * getInstance() {
		if (!Renderer::instance) {
			Renderer::instance = new Renderer();
		}
		
		return Renderer::instance;
		
	}
};
