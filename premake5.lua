workspace "Calculator"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDirs = {}
    IncludeDirs["ClcCore"] = "Calculator-Core/src"
    IncludeDirs["ClcCli"] = "Calculator-CLI/src"

    include ("Calculator-Core")
    include ("Calculator-CLI")