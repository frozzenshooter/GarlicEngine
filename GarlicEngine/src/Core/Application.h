#pragma once
#include <vector>
#include "Component.h"
#include "Logging/Log.h"

namespace Garlic {

    class Application {
    private:
        Application()
            :m_Running(true), m_StartUpSuccessful(false), m_StartUpDone(false)
        {
        };

        void StartUp();
        void Shutdown();

    public:
        ~Application() {
            Shutdown();
        };

        Application(Application const&) = delete;
        void operator=(Application const&) = delete;

        static Application& GetInstance();
        void Run();

    private:
        bool m_Running;
        bool m_StartUpSuccessful;
        bool m_StartUpDone;
        Logger m_Logger;
    };
}