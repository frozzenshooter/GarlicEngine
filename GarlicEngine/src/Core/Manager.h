#pragma once
#include <string>

namespace Garlic {

    class Manager {

    public:
        Manager(): m_Name("Manager") {}
        ~Manager() {}

        inline const std::string& GetName() const { return m_Name; }

        virtual bool StartUp() {}
        virtual bool ShutDown() {}

    protected:
        std::string m_Name;
    };
}