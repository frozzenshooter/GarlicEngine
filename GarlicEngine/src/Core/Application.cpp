#include "gepch.h"
#include "Application.h"

namespace Garlic {

    Application& Application::GetInstance() {

        static Application app;

        if (!app.m_StartUpDone) {
            app.StartUp();
        }

        return app;
    }

    void Application::StartUp() {

        // startup logger as first element
        m_Logger.StartUp();

        GE_CORE_INFO("StartUp of components started");

        // StartUp all components of the engine
        m_StartUpSuccessful = true;

        if (m_StartUpSuccessful) {
            GE_CORE_INFO("StartUp was successul");
        } else {
            GE_CORE_ERROR("StartUp wasn't successfull");
        }

        m_StartUpDone = true;
    }

    void Application::Run() {

        if (m_StartUpSuccessful) {
           
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
        else {
            GE_CORE_ERROR("Running not possible, because StartUp wasn't successfull!");
        }
    }

    void Application::Shutdown() {

        GE_CORE_INFO("Shutdown started!");

        // Shutdown managers in reverse order


        GE_CORE_INFO("Shutdown successful");
        m_Logger.ShutDown();
    }
};