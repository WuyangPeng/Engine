// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:03)

// ����̨��ɫ����
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
