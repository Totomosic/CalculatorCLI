project "Calculator-CLI"
    location ""
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("../bin/" .. outputdir .. "/Calculator-CLI")
    objdir ("../bin-int/" .. outputdir .. "/Calculator-CLI")
    targetname("calc")
    
    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs
    {
        "../%{IncludeDirs.ClcCore}",
        "src"
    }

    links
    {
        "Calculator-Core"
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