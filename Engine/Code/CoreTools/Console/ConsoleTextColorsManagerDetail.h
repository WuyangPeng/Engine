///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 15:30)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H

#include "ConsoleTextColorsManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleTextColorsManager<Handle>::ConsoleTextColorsManager(TextColour textColor, bool intensified)
    : consoleColors{ ConsoleColorsHandle::Create() }, textColor{ textColor }, intensified{ intensified }
{
    SetTextColor();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleTextColorsManager<Handle>::~ConsoleTextColorsManager() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        ResetTextColor();
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleTextColorsManager<Handle>::SetTextColor()
{
    if (intensified)
    {
        consoleColors.SetTextIntensifiedColor(textColor);
    }
    else
    {
        consoleColors.SetTextColor(textColor);
    }
}

template <CoreTools::StandardHandle Handle>
void CoreTools::ConsoleTextColorsManager<Handle>::ResetTextColor()
{
    consoleColors.ResetColor();
}

#ifdef OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleTextColorsManager<Handle>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_DETAIL_H
