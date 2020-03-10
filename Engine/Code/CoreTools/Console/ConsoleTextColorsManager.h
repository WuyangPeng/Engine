// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:03)

// 控制台颜色管理
#ifndef CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H

#include "ConsoleColorsDetail.h"

namespace CoreTools
{
	template <StandardHandle Handle>
	class ConsoleTextColorsManager
	{
	public:
		using ClassType = ConsoleTextColorsManager;

	public:
		explicit ConsoleTextColorsManager(TextColour textColor, bool intensified = false);
		~ConsoleTextColorsManager();

		CLASS_INVARIANT_DECLARE;

	private:
		void SetTextColor();
		void ResetTextColor();

	private:
		using ConsoleColorsHandle = ConsoleColors<Handle>;

	private:
		ConsoleColorsHandle m_ConsoleColors;
		TextColour m_TextColor;
		bool m_Intensified;
	};
}

#endif // CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
