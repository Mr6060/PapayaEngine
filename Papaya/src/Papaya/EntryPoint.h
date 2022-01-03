#pragma once

#ifdef PY_PLATFORM_WINDOWS

extern Papaya::Application* Papaya::CreateApplication();

int main(int argc, char** argv) {
	auto app = Papaya::CreateApplication();
	app->Run();
	delete app;
}

#endif