#pragma once
#include <Core\Application.h>

#ifdef GE_PLATFORM_WINDOWS

extern Garlic::Application* Garlic::CreateApplication();

int main(int argc, char** argv) {

    Garlic::Log::Init();

    auto app = Garlic::CreateApplication();
    app->Run();
    delete app;
}

#endif