// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:04)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H

#include "ConsoleTextColorsManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleTextColorsManager<Handle>
	::ConsoleTextColorsManager(TextColour textColor, bool intensified)
	:m_ConsoleColors{}, m_TextColor{ textColor }, m_Intensified{ intensified }
{
	SetTextColor();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleTextColorsManager<Handle>
	::~ConsoleTextColorsManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	EXCEPTION_TRY
	{
		ResetTextColor();
	}
	EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleTextColorsManager<Handle>
	::SetTextColor()
{
	if (m_Intensified)
	{
		m_ConsoleColors.SetTextIntensifiedColor(m_TextColor);
	}
	else
	{
		m_ConsoleColors.SetTextColor(m_TextColor);
	}
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleTextColorsManager<Handle>
	::ResetTextColor()
{
	m_ConsoleColors.ResetColor();
}

#ifdef OPEN_CLASS_INVARIANT
template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleTextColorsManager<Handle>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

#endif // CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H
