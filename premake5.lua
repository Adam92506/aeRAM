workspace "aeRAM"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Eram"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Eram/vendor/GLFW/include"
IncludeDir["Glad"] = "Eram/vendor/Glad/include"
IncludeDir["imgui"] = "Eram/vendor/imgui"
IncludeDir["glm"] = "Eram/vendor/glm"

include "Eram/vendor/GLFW"
include "Eram/vendor/Glad"
include "Eram/vendor/imgui"

project "Eram"
	location "Eram"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "erpch.h"
	pchsource "Eram/src/erpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib",
		"ImGui"
	}

	filter "system:windows"
		systemversion "latest"
		defines 
		{
			"ER_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines
		{
			"ER_DEBUG",
			"ER_ENABLE_ASSERTS",
			"ER_LOG_LEVEL_TRACE"
		}
		symbols "on"

	filter "configurations:Release"
		defines
		{
			"ER_RELEASE",
			"ER_LOG_LEVEL_INFO"
		}
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines
		{
			"ER_DIST",
			"ER_LOG_LEVEL_INFO"
		}
		runtime "Release"
		optimize "on"