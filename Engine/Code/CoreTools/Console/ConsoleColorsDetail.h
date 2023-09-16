///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 10:42)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H

#include "ConsoleColors.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleColors<Handle> CoreTools::ConsoleColors<Handle>::Create()
{
    return ConsoleColors{ DisableNotThrow::Disable };
}

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleColors<Handle>::ConsoleColors(DisableNotThrow disableNotThrow)
    : console{ ConsoleInstanceHandle::Create() }, textColor{ TextColour::White }, backgroundColor{ BackgroundColour::Black }
{
    System::UnusedFunction(disableNotThrow);

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

    constexpr auto defaultTextColor = TextColour::White;
    constexpr auto defaultBackgroundColor = BackgroundColour::Black;

    if (auto handle = console.GetHandle();
        !System::SetSystemConsoleTextAttribute(handle, defaultTextColor, defaultBackgroundColor, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ������̨��ɫʧ�ܡ�"s))
    }
    else
    {
        textColor = defaultTextColor;
        backgroundColor = defaultBackgroundColor;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetTextColor(TextColour aTextColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (auto handle = console.GetHandle();
        !System::SetSystemConsoleTextAttribute(handle, aTextColor, backgroundColor, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ÿ���̨�ı���ɫʧ�ܡ�"s))
    }
    else
    {
        textColor = aTextColor;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetTextIntensifiedColor(TextColour aTextColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    aTextColor |= TextColour::Intensified;
    SetTextColor(aTextColor);
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetBackgroundColor(BackgroundColour aBackgroundColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (auto handle = console.GetHandle();
        !System::SetSystemConsoleTextAttribute(handle, textColor, aBackgroundColor, System::ConsoleCommon::Default))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ÿ���̨������ɫʧ�ܡ�"s));
    }
    else
    {
        backgroundColor = aBackgroundColor;
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleColors<Handle>::SetBackgroundIntensifiedColor(BackgroundColour aBackgroundColor)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    aBackgroundColor |= BackgroundColour::Intensified;
    SetBackgroundColor(aBackgroundColor);
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_DETAIL_H
