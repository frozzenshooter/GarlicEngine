#include "Manager.h"
#include <vector>
#include <memory>

namespace Garlic {

    class CoreManager {

    public:
        CoreManager();
        virtual ~CoreManager() {}

        void StartUp();
        void Run();
        void Shutdown();

    private:
        bool m_Running;
        bool m_StartUpSuccessful;
        std::vector<Manager*> m_Managers;
    };
}