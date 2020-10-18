#include <iostream>
#include <GarlicEngine.h>

using namespace Garlic;

int main() {

    //TODO: Solution for logger -> if the macro is used bevor the core manager init -> read access problem

    CoreManager& coreManager(CoreManager::GetInstance());
    coreManager.StartUp();    
    GE_INFO("Logging from app");
    coreManager.Run();
    coreManager.Shutdown();
}