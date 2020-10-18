#pragma once
#include <vector>
#include "Component.h"
#include "Logging/Log.h"

namespace Garlic {

    class CoreManager {
    private:
        CoreManager() 
            :m_Running(true), m_StartUpSuccessful(false) 
        {

        };

    public:
       
        CoreManager(CoreManager const&) = delete;
        void operator=(CoreManager const&) = delete;
        ~CoreManager() {};

        static CoreManager& GetInstance();

        void StartUp();
        void Run();
        void Shutdown();
    private:
        bool m_Running;
        bool m_StartUpSuccessful;
        Logger m_Logger;

    };
}