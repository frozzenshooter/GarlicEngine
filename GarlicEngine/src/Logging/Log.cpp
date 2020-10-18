#include "gepch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Garlic {

    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    bool Logger::StartUp()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("Core");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("App");
        s_ClientLogger->set_level(spdlog::level::trace);

        return true;
    }

    bool Logger::ShutDown() {
        return true;
    }
}