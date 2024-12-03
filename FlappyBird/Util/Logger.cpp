#include "FlappyBird/Util/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/ostream_sink.h>

#include <mutex>

namespace FlappyBird
{
	void Logger::Init(const std::string& name)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt(name);
		s_Logger->set_level(spdlog::level::trace);

		/*std::vector<spdlog::sink_ptr>& sinks{ s_Logger->sinks() };
		sinks[0] = std::make_shared<spdlog::sinks::ostream_sink_st>(s_Stream);*/
		FLAPPYBIRD_LOG_INFO("FlappyBirdLogger->Initialized!");
	}

	void Logger::Destroy()
	{
		FLAPPYBIRD_LOG_INFO("FlappyBirdLogger->Destroyed!");
	}

	void Logger::SaveLastLog()
	{
		s_Logs.push_back(s_Stream.str());
		s_Stream.str("");
	}

	void Logger::Clear()
	{
		s_Logs.clear();
	}

	const std::vector<std::string>& Logger::GetLogs()
	{
		return s_Logs;
	}
}
