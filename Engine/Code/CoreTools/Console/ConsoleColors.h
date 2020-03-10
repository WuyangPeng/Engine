// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:02)

// ����̨��ʾ��ɫ��
#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H

#include "ConsoleInstanceDetail.h"

namespace CoreTools
{
	template <StandardHandle Handle>
	class ConsoleColors
	{
	public:
		using ClassType = ConsoleColors<Handle>;

	public:
		ConsoleColors();

		CLASS_INVARIANT_DECLARE;

		void ResetColor();
		void SetTextColor(TextColour textColor);
		void SetTextIntensifiedColor(TextColour textColor);
		void SetBackgroundColor(BackgroundColour backgroundColor);
		void SetBackgroundIntensifiedColor(BackgroundColour backgroundColor);

	private:
		using ConsoleInstanceHandle = ConsoleInstance<Handle>;

	private:
		ConsoleInstanceHandle m_Console;
		TextColour m_TextColor;
		BackgroundColour m_BackgroundColor;
	};
}


#endif // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H