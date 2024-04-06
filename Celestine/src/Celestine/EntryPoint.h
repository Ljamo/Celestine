#pragma once

#ifdef WL_PLATFORM_WINDOWS

extern Celestine::Application* Celestine::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Celestine {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Celestine::Application* app = Celestine::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#ifdef WL_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Celestine::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Celestine::Main(argc, argv);
}

#endif // WL_DIST

#endif // WL_PLATFORM_WINDOWS
