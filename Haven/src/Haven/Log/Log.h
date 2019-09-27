#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <memory>
#include <Haven/Core.h>

namespace Haven
{
	class HAVEN_API Log
	{
	public:
		static void Init();
		static void Shutdown();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define HV_CORE_TRACE(...)	Haven::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HV_CORE_INFO(...)	Haven::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HV_CORE_WARN(...)	Haven::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HV_CORE_ERROR(...)	Haven::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HV_CORE_CRITICAL(...)	Haven::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define HV_TRACE(...)		Haven::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HV_INFO(...)		Haven::Log::GetClientLogger()->info(__VA_ARGS__)
#define HV_WARN(...)		Haven::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HV_ERROR(...)		Haven::Log::GetClientLogger()->error(__VA_ARGS__)
#define HV_CRITICAL(...)	Haven::Log::GetClientLogger()->critical(__VA_ARGS__)

#if defined(DEBUG)
	#define HV_CORE_DEBUG(...)	Haven::Log::GetCoreLogger()->debug(__VA_ARGS__)
	#define HV_DEBUG(...)		Haven::Log::GetClientLogger()->debug(__VA_ARGS__)
#else
	#define HV_CORE_DEBUG(...)
	#define HV_DEBUG(...)
#endif