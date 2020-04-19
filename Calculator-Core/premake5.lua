project "Calculator-Core"
    location ""
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("../bin/" .. outputdir .. "/Calculator-Core")
    objdir ("../bin-int/" .. outputdir .. "/Calculator-Core")
    
    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs
    {
        "src"
    }

    links
    {
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter "system:linux"
        systemversion "latest"

        defines
        {
        }

        links 
        {
        }

    filter "system:macosx"
        systemversion "latest"

        defines
        {
        }

        links 
        {
        }

    filter "configurations:Debug"
        defines "CLC_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CLC_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "CLC_DIST"
        runtime "Release"
        optimize "on"