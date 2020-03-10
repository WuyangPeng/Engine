// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:03)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H

#include "ConsoleColors.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleColors<Handle>
	::ConsoleColors()
	:m_Console{}, m_TextColor{ TextColour::White }, m_BackgroundColor{ BackgroundColour::Black }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleColors<Handle>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>
	::ResetColor()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto handle = m_Console.GetHandle();

	constexpr auto defaultTextColour = TextColour::White;
	constexpr auto defaultBackgroundColour = BackgroundColour::Black;

	if (!System::SetSystemConsoleTextAttribute(handle, defaultTextColour, defaultBackgroundColour, System::ConsoleCommon::Default))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ʼ������̨��ɫʧ�ܡ�"));
	}
	else
	{
		m_TextColor = defaultTextColour;
		m_BackgroundColor = defaultBackgroundColour;
	}
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>
	::SetTextColor(TextColour textColor)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto handle = m_Console.GetHandle();

	if (!System::SetSystemConsoleTextAttribute(handle, textColor, m_BackgroundColor, System::ConsoleCommon::Default))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ÿ���̨�ı���ɫʧ�ܡ�"));
	}
	else
	{
		m_TextColor = textColor;
	}
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>
	::SetTextIntensifiedColor(TextColour textColor)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	textColor |= TextColour::Intensified;
	SetTextColor(textColor);
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>
	::SetBackgroundColor(BackgroundColour backgroundColor)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto handle = m_Console.GetHandle();

	if (!System::SetSystemConsoleTextAttribute(handle, m_TextColor, backgroundColor, System::ConsoleCommon::Default))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���ÿ���̨������ɫʧ�ܡ�"));
	}
	else
	{
		m_BackgroundColor = backgroundColor;
	}
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>
	::SetBackgroundIntensifiedColor(BackgroundColour backgroundColor)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	backgroundColor |= BackgroundColour::Intensified;
	SetBackgroundColor(backgroundColor);
}

#endif // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
