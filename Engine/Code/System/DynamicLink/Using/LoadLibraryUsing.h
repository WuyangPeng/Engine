// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:46)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using DynamicLinkModule = HMODULE; 
	using DynamicLinkProcess = FARPROC;
	using DynamicLinkCharType = TCHAR;
	using DynamicLinkString = String;
	constexpr WindowDWord g_MaxPath{ MAX_PATH };

	#define DYNAMIC_LINK_TEXT(quote) SYSTEM_TEXT(quote)

#else // !SYSTEM_PLATFORM_WIN32		

	using DynamicLinkModule = void*; 
	using DynamicLinkProcess = int(*)();
	using DynamicLinkCharType = char;
	using DynamicLinkString = std::string;
	constexpr WindowDWord g_MaxPath{ 260 };

	#define DYNAMIC_LINK_TEXT(quote) quote

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
