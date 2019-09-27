#pragma once

#include <Haven/Core.h>

namespace Haven
{
	class HAVEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		static Application* s_Instance;
	};

	// Defined by client.
	Application* CreateApplication();
}