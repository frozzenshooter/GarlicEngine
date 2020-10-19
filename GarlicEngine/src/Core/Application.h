#pragma once
#include <vector>
#include "Component.h"
#include "Logging/Log.h"

namespace Garlic {

    class Application {
    public:
        Application();
        virtual ~Application() {};

        Application(Application const&) = delete;
        void operator=(Application const&) = delete;

        inline static Application& Get() { return *s_Instance; }
        void Run();

    private:
        bool m_Running;
        static Application* s_Instance;
    };

    Application* CreateApplication();
}

