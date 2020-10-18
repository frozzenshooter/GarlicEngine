#pragma once

#include <memory>
#include "Core/Component.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Garlic {

    class Logger : public Component{
    public:
        Logger() : Component("Logger") 
        {
        }

        virtual bool StartUp() override;
        virtual bool ShutDown() override;

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define GE_CORE_TRACE(...) ::Garlic::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)  ::Garlic::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)  ::Garlic::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::Garlic::Logger::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define GE_TRACE(...) ::Garlic::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)  ::Garlic::Logger::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)  ::Garlic::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::Garlic::Logger::GetClientLogger()->error(__VA_ARGS__)