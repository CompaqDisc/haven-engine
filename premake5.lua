workspace "Haven"
	architecture "x86_64"
	configurations { "Debug", "Release" }

project "Haven"
	kind "SharedLib"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir  "build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

	files { "%{prj.name}/src/**.cc", "%{prj.name}/src/**.h" }
	includedirs { "%{prj.name}/src/"}
	includedirs { "vendor/spdlog/include" }

	cppdialect "C++14"

	filter "configurations:Debug"
		defines { "DEBUG", "HAVEN_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

	filter "system:windows"
		defines { "HV_PLATFORM_WINDOWS", "HV_BUILD_DLL" }

	filter "system:linux"
		defines { "HV_PLATFORM_LINUX" }

project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir  "build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

	files { "%{prj.name}/src/**.cc", "%{prj.name}/src/**.h" }
	includedirs { "Haven/src/"}
	includedirs { "vendor/spdlog/include" }
	defines { "HV_CLIENT" }
	links { "Haven" }

	cppdialect "C++14"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

	filter "system:windows"
		defines { "HV_PLATFORM_WINDOWS" }

	filter "system:linux"
		defines { "HV_PLATFORM_LINUX" }