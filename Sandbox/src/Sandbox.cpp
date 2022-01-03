#include <Papaya.h>

class Sandbox : public Papaya::Application {

public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Papaya::Application* Papaya::CreateApplication() {
	return new Sandbox();
}