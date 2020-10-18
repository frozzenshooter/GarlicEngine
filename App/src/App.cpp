#include <iostream>
#include <GarlicEngine.h>

int main() {

    Garlic::CoreManager coreManager;

    coreManager.StartUp();
    coreManager.Run();
    coreManager.Shutdown();
}