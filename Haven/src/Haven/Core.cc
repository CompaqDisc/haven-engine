#include <Haven/Core.h>
#include <Haven/Log/Log.h>

namespace Haven {
	void HAVEN_API Init()
	{
		Haven::Log::Init();
		HV_CORE_INFO("Logging Initialized.");
		HV_CORE_INFO("Haven Engine {}. Copyright(c) 2019, Bradan J. Wolbeck (CompaqDisc).", HAVEN_VERSION);

		#if defined(HAVEN_DEBUG)
		HV_CORE_DEBUG("This is a debug build of Haven.");
		#endif
	}

	void HAVEN_API Shutdown()
	{
		HV_CORE_INFO("Haven has reached shutdown, goodbye.");
	}
}