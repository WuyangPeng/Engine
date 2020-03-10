// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:03)

#ifndef CORE_TOOLS_CONSOLE_FWD_H
#define CORE_TOOLS_CONSOLE_FWD_H

#include "Flags/ConsoleColorsFlags.h"

namespace CoreTools
{
	template <StandardHandle Handle>
	class ConsoleInstance;

	template <StandardHandle Handle>
	class ConsoleColors;

	template <StandardHandle Handle>
	class ConsoleTextColorsManager;

	class ConsoleAlloc;
}

#endif // CORE_TOOLS_CONSOLE_FWD_H