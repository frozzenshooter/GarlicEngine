#include "gepch.h"
#include "CoreManager.h"

namespace Garlic {

    CoreManager& CoreManager::GetInstance() {

        static CoreManager manager;

        // Startup logger by creating the core to be able to log other functions
        manager.m_Logger.StartUp();

        return manager;
    }

    void CoreManager::StartUp() {
        GE_CORE_INFO("StartUp of components started");

        // StartUp all components of the engine
        m_StartUpSuccessful = true;

        if (m_StartUpSuccessful) {
            GE_CORE_INFO("StartUp was successul");
        } else {
            GE_CORE_ERROR("StartUp wasn't successfull");
        }
    }

    void CoreManager::Run() {

        if (m_StartUpSuccessful) {
            while (m_Running) {
                // CENTRAL LOOP

                GE_CORE_INFO("Running!");

            }
        }
        else {
            GE_CORE_ERROR("Running not possible, because StartUp wasn't successfull!");
        }

    }

    void CoreManager::Shutdown() {

        GE_CORE_INFO("Shutdown started!");

        // Shutdown managers in reverse order


        GE_CORE_INFO("Shutdown successful");
        m_Logger.ShutDown();
    }
};