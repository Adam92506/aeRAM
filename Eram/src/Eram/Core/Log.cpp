#include "erpch.h"
#include "Log.h"

namespace Eram {

	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt("aeRAM");

		#ifdef MC_LOG_LEVEL_TRACE
		s_Logger->set_level(spdlog::level::trace);
		#elif MC_LOG_LEVEL_INFO
		s_Logger->set_level(spdlog::level::info);
		#elif MC_LOG_LEVEL_WARN
		s_Logger->set_level(spdlog::level::warn);
		#else	
		s_Logger->set_level(spdlog::level::trace);
		#endif
	}
}