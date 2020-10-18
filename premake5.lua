workspace "GarlicEngine"
    architecture "x64"
    startproject "App"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--IncludeDir = {}

--group "Dependencies"
--group ""

project "GarlicEngine"
    location "GarlicEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "gepch.h"
	pchsource "GarlicEngine/src/gepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src" 
    }

    links
    {

    }

    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "GE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize "on"

project "App"
        location "App"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "GarlicEngine/src"
        }

        links
        {
            "GarlicEngine"
        }

    filter "system:windows"
        systemversion "latest"
        defines
        {
            "GE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "GE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "GE_RELEASE"
        runtime "Release"
        optimize "on"