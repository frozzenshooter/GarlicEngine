#include <iostream>
#include <GarlicEngine.h>

using namespace Garlic;

int main() {

    CoreManager& coreManager(CoreManager::GetInstance());

    coreManager.StartUp();
    coreManager.Run();
    coreManager.Shutdown();
}