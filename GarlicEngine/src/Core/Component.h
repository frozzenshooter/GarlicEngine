#pragma once

namespace Garlic {

    class Component {

    public:
        Component(): m_Name("Manager") {}
        ~Component() {}

        inline const std::string& GetName() const { return m_Name; }

        virtual bool StartUp() {}
        virtual bool ShutDown() {}

    protected:
        std::string m_Name;
    };
}