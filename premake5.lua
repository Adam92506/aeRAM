workspace "aeRAM"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "aeRAM"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

project "aeRAM"
	location "aeRAM"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	filter "system:windows"
		systemversion "latest"
		defines 
		{
			"PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
		}
		symbols "on"

	filter "configurations:Release"
		defines
		{
		}
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines
		{
		}
		runtime "Release"
		optimize "on"