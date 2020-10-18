#include "CoreManager.h"

namespace Garlic {
    
    CoreManager::CoreManager() 
        :m_Running(true), m_StartUpSuccessful(false)
    {

    }

    void CoreManager::StartUp() {

        //m_Managers.push_back(nullptr);


        m_StartUpSuccessful = true;
    }

    void CoreManager::Run() {

        if (m_StartUpSuccessful) {
            while (m_Running) {
                // CENTRAL LOOP

            }
        }
        else {
            //TODO:: LOG ERROR - Managers not started
        }

    }

    void CoreManager::Shutdown() {

        // Shutdown managers in reverse order
        for (std::vector<Manager*>::reverse_iterator pManager = m_Managers.rbegin(); pManager != m_Managers.rend(); ++pManager) {
            (*pManager)->ShutDown();
        }
    }
}