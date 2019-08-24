workspace "Haven"
	architecture "x86_64"
	configurations { "Debug", "Release" }

project "Haven"
	kind "SharedLib"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir  "build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

	files { "%{prj.name}/src/**.cc", "%{prj.name}/src/**.h" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir  "build/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

	files { "%{prj.name}/src/**.cc", "%{prj.name}/src/**.h" }
	includedirs { "Haven/src" }
	links { "Haven" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"