#include <Haven/Log/Log.h>

#include <chrono>
#include <ctime>
#include <string>
#include <vector>

#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/bundled/time.h>

namespace Haven
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string coreLogfile = fmt::format("{:%Y%m%dT%H%M%S}.engine.log", *std::localtime(&now));
		std::string clientLogfile = fmt::format("{:%Y%m%dT%H%M%S}.client.log", *std::localtime(&now));

		std::vector<spdlog::sink_ptr> coreSinks;
		coreSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		coreSinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(coreLogfile));
		s_CoreLogger = std::make_shared<spdlog::logger>("engine", begin(coreSinks), end(coreSinks));
		s_CoreLogger->set_pattern("[%X] %^[%n/%l]:\t%v%$");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CoreLogger->flush_on(spdlog::level::trace);

		std::vector<spdlog::sink_ptr> clientSinks;
		clientSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		clientSinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(clientLogfile));
		s_ClientLogger = std::make_shared<spdlog::logger>("client", begin(clientSinks), end(clientSinks));
		s_ClientLogger->set_pattern("[%X] %^[%n/%l]:\t%v%$");
		s_ClientLogger->set_level(spdlog::level::trace);
		s_ClientLogger->flush_on(spdlog::level::trace);
	}

	void Log::Shutdown()
	{
		spdlog::shutdown();
	}
}
