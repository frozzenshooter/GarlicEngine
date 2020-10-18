#include "gepch.h"
#include "CoreManager.h"

namespace Garlic {

    CoreManager& CoreManager::GetInstance() {

        static CoreManager manager;

        return manager;
    }

    void CoreManager::StartUp() {

        //m_Components.push_back(nullptr);


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
        for (std::vector<Component*>::reverse_iterator pComponent = m_Components.rbegin(); pComponent != m_Components.rend(); ++pComponent) {
            (*pComponent)->ShutDown();
        }
    }
};