#include <iostream>
#include <GarlicEngine.h>

using namespace Garlic;

int main() {

    // TODO: Solution for logger -> if the macro is used bevor the core manager init -> read access problem
    // Possible solution -> Logger has to be accessed through coremanager

    Application& app(Application::GetInstance());
    GE_INFO("1");
    app.Run();

}