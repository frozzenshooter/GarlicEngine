#include "gepch.h"
#include "Application.h"
#include "Macros.h"

namespace Garlic {

    Application* Application::s_Instance = nullptr;

    Application::Application(): m_Running(true)
    {
        GE_CORE_ASSERT(!s_Instance, "Application already exists");
        s_Instance = this;
    }

    void Application::Run() {

        int i = 100;
        while (m_Running) {
            // MAIN LOOP
            i--;
            GE_CORE_INFO("Running!");

            if (i <= 1) {
                m_Running = false;
            }
        }
    }
};