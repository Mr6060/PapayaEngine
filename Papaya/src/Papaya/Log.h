#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Papaya {

	class PAPAYA_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//core log macros
#define PY_CORE_TRACE(...)   ::Papaya::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PY_CORE_INFO(...)    ::Papaya::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PY_CORE_WARN(...)    ::Papaya::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PY_CORE_ERROR(...)   ::Papaya::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PY_CORE_FATAL(...)   ::Papaya::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define PY_TRACE(...)        ::Papaya::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PY_INFO(...)         ::Papaya::Log::GetClientLogger()->info(__VA_ARGS__)
#define PY_WARN(...)         ::Papaya::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PY_ERROR(...)        ::Papaya::Log::GetClientLogger()->error(__VA_ARGS__)
#define PY_FATAL(...)        ::Papaya::Log::GetClientLogger()->fatal(__VA_ARGS__)