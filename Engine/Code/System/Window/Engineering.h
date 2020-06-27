// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.1.1.0 (2020/05/02 1:09)

#ifndef SYSTEM_HELPER_ENGINEERING_H
#define SYSTEM_HELPER_ENGINEERING_H

#include "System/Helper/UserMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/DynamicLink/LibraryTools.h"

#include <array>

namespace System
{
	inline String GetEngineeringSuffix()
	{
		String suffix;

		suffix += SYSTEM_TEXT("");

	#ifdef BUILDING_SYSTEM_STATIC
		suffix += SYSTEM_TEXT("Static");
	#endif // BUILDING_SYSTEM_STATIC

	#ifdef _DEBUG
		suffix += SYSTEM_TEXT("D");
	#endif // _DEBUG

		return suffix;
	}

	inline String GetEngineeringExeSuffix()
	{
	#ifdef SYSTEM_PLATFORM_WIN32
		return SYSTEM_TEXT(".exe");
	#else // !SYSTEM_PLATFORM_WIN32
		return SYSTEM_TEXT("");
	#endif // BUILDING_SYSTEM_STATIC 		
	}

	inline String GetEngineeringDirectory()
	{
		std::array<DynamicLinkCharType, g_MaxPath> moduleFileName{};
		const auto maxFileNameLength = GetDynamicLinkFileName(nullptr, moduleFileName.data(), g_MaxPath);

		if (maxFileNameLength == 0)
		{
			return String{ };
		}

		String name{ moduleFileName.data() };

		const auto pos = name.find_last_of(SYSTEM_TEXT("\\"));
		if (pos == String::npos)
		{
			return String{ };
		}

		return name.substr(0, pos + 1);
	}

	// 这个模板没有定义，用来让编译器打印某个型别的类型。
	template<typename T>
	class TypeDisplayer;
}

#endif // SYSTEM_HELPER_ENGINEERING_H
