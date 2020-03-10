// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H
#define SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using ConsoleCursorInfo = CONSOLE_CURSOR_INFO;
	using ConsoleCursorInfoPtr = PCONSOLE_CURSOR_INFO;

#else // !SYSTEM_PLATFORM_WIN32

	struct ConsoleCursorInfo
	{
		WindowDWord dwSize;
		WindowBool bVisible;
	};

	using ConsoleCursorInfoPtr = ConsoleCursorInfo*;

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_CONSOLE_CONSOLE_CURSOR_USING_H