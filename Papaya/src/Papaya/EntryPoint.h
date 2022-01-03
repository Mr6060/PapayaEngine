#pragma once

#ifdef PY_PLATFORM_WINDOWS

extern Papaya::Application* Papaya::CreateApplication();

int main(int argc, char** argv) {

	Papaya::Log::Init();
	PY_CORE_WARN("Logging INIT successful");
	PY_INFO("Hello there");

	auto app = Papaya::CreateApplication();
	app->Run();
	delete app;
}

#endif
