///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 18:50)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H

#include "ConsoleColors.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleColors<Handle>::ConsoleColors(DisableNotThrow disableNotThrow)
    : console{ disableNotThrow }, m_TextColor{ TextColour::White }, m_BackgroundColor{ BackgroundColour::Black }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleColors<Handle>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::ResetColor()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto handle = console.GetHandle();

    constexpr auto defaultTextColour = TextColour::White;
    constexpr auto defaultBackgroundColour = BackgroundColour::Black;

    if (!System::SetSystemConsoleTextAttribute(handle, defaultTextColour, defaultBackgroundColour, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("初始化控制台颜色失败。"s));
    }
    else
    {
        m_TextColor = defaultTextColour;
        m_BackgroundColor = defaultBackgroundColour;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetTextColor(TextColour textColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto handle = console.GetHandle();

    if (!System::SetSystemConsoleTextAttribute(handle, textColor, m_BackgroundColor, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置控制台文本颜色失败。"s));
    }
    else
    {
        m_TextColor = textColor;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetTextIntensifiedColor(TextColour textColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    textColor |= TextColour::Intensified;
    SetTextColor(textColor);
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetBackgroundColor(BackgroundColour backgroundColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto handle = console.GetHandle();

    if (!System::SetSystemConsoleTextAttribute(handle, m_TextColor, backgroundColor, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置控制台背景颜色失败。"s));
    }
    else
    {
        m_BackgroundColor = backgroundColor;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetBackgroundIntensifiedColor(BackgroundColour backgroundColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    backgroundColor |= BackgroundColour::Intensified;
    SetBackgroundColor(backgroundColor);
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
