#pragma once

#include <string>

namespace Garlic {

    class Component {

    public:
        Component(const std::string& name = "Manager") : m_Name(name) {}
        ~Component() {}

        inline const std::string& GetName() const { return m_Name; }

        virtual bool StartUp() = 0;
        virtual bool ShutDown() = 0;

    private:
        std::string m_Name;
    };
}