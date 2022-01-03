#pragma once

#include "Core.h"

namespace Papaya {

	class PAPAYA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//defined in client;
	Application* CreateApplication();

}

