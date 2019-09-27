#pragma once

#define HAVEN_VERSION "Alpha 2019.09.11"

#define HAVEN_API
#ifdef HV_PLATFORM_WINDOWS
	#ifdef HV_BUILD_DLL
		#define HAVEN_API __declspec( dllexport )
	#else
		#define HAVEN_API __declspec( dllimport )
	#endif
	#define HV_SUPPORTED_PLATFORM
#endif
#ifdef HV_PLATFORM_LINUX
	#define HV_SUPPORTED_PLATFORM
#endif
#ifndef HV_SUPPORTED_PLATFORM
	#error "Unsupported platform!"
#endif

namespace Haven {
	void HAVEN_API Init();
	void HAVEN_API Shutdown();
}