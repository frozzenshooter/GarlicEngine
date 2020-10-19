#pragma once

#include <memory>
#include "Core/Component.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Garlic {

    class Log
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

// Core log macros
#define GE_CORE_TRACE(...) ::Garlic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)  ::Garlic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)  ::Garlic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::Garlic::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define GE_TRACE(...) ::Garlic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)  ::Garlic::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)  ::Garlic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::Garlic::Log::GetClientLogger()->error(__VA_ARGS__)