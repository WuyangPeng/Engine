// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:34)

#ifndef SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H
#define SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32 

	using ConsoleCoord = COORD;
	using ConsoleCoordPtr = PCOORD;

#else // !SYSTEM_PLATFORM_WIN32 

	struct ConsoleCoord
	{
		int16_t X;
		int16_t Y;
	};
	using ConsoleCoordPtr = ConsoleCoord*;

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_CONSOLE_CONSOLE_COLOURS_USING_H