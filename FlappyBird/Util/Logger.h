#pragma once

#include <spdlog/spdlog.h>

#include <string>
#include <memory>
#include <vector>
#include <sstream>

namespace FlappyBird
{
	class Logger
	{
	public:
		static void Init(const std::string& name = "FlappyBirdLogger");
		static void Destroy();
		inline static std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }

		static void SaveLastLog();
		static void Clear();
		static const std::vector<std::string>& GetLogs();

	private:
		inline static std::shared_ptr<spdlog::logger> s_Logger;
		inline static std::vector<std::string> s_Logs;
		inline static std::ostringstream s_Stream;
	};
}

#define FLAPPYBIRD_LOG_INFO(...)		(FlappyBird::Logger::GetLogger()->info(__VA_ARGS__), FlappyBird::Logger::SaveLastLog())
#define FLAPPYBIRD_LOG_WARN(...)		(FlappyBird::Logger::GetLogger()->warn(__VA_ARGS__), FlappyBird::Logger::SaveLastLog())
#ifdef FLAPPYBIRD_DEBUG
	#define FLAPPYBIRD_LOG_DEBUG(...)		(FlappyBird::Logger::GetLogger()->debug(__VA_ARGS__), FlappyBird::Logger::SaveLastLog())
#else
	#define FLAPPYBIRD_LOG_DEBUG(...)
#endif
#define FLAPPYBIRD_LOG_ERROR(...)		(FlappyBird::Logger::GetLogger()->error(__VA_ARGS__), FlappyBird::Logger::SaveLastLog())
#define FLAPPYBIRD_LOG_CRITICAL(...)	(FlappyBird::Logger::GetLogger()->critical(__VA_ARGS__), FlappyBird::Logger::SaveLastLog(), throw)
#define FLAPPYBIRD_LOG_TRACE(...)		(FlappyBird::Logger::GetLogger()->trace(__VA_ARGS__), FlappyBird::Logger::SaveLastLog(), __VA_ARGS__))
