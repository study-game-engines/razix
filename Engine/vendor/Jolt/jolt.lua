project "Jolt"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

     includedirs
    {
         "./",
         "./Jolt"
    }

    files
    {
        "Jolt/**.h",
        "Jolt/**.cpp"
    }

    filter "system:windows"
        systemversion "latest"
        cppdialect "C++20"
        staticruntime "off"

    filter "configurations:Debug"
        defines { "RAZIX_DEBUG", "_DEBUG" }
        symbols "On"
        runtime "Debug"
        optimize "Off"

    filter "configurations:Release"
        defines { "RAZIX_RELEASE", "NDEBUG" }
        optimize "Speed"
        symbols "On"
        runtime "Release"

    filter "configurations:Distribution"
        defines { "RAZIX_DISTRIBUTION", "NDEBUG" }
        symbols "Off"
        optimize "Full"
        runtime "Release"
