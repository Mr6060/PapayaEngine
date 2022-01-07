#include "pypch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Papaya {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			PY_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			PY_TRACE(e);
		}

		while (true);
	}

}