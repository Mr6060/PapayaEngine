#pragma once

#ifdef PY_PLATFORM_WINDOWS
	#ifdef PY_BUILD_DLL
		#define PAPAYA_API __declspec(dllexport)
	#else
		#define PAPAYA_API __declspec(dllimport)
	#endif
#else
	#error Papaya only supports windows!
#endif

