workspace "Papaya"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Papaya"
	
	location "Papaya"
	kind "SharedLib"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pypch.h"
	pchsource "Papaya/src/pypch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/sfml/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PY_PLATFORM_WINDOWS",
			"PY_BUILD_DLL"
		
		}
		
		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "PY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PY_DIST"
		optimize "On"


project "Sandbox"
	 location "Sandbox"
	 kind "ConsoleApp"
	 language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Papaya/vendor/spdlog/include",
		"Papaya/src"
	}

	links{
		"Papaya"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"PY_PLATFORM_WINDOWS"
		
		}


	filter "configurations:Debug"
		defines "PY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PY_DIST"
		optimize "On"
