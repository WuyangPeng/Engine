//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 15:13)

// 控制台颜色管理
#ifndef CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H

#include "ConsoleColorsDetail.h"

namespace CoreTools
{
    template <StandardHandle Handle>
    class ConsoleTextColorsManager final
    {
    public:
        using ClassType = ConsoleTextColorsManager;

    public:
        explicit ConsoleTextColorsManager(TextColour textColor, bool intensified = false);
        ~ConsoleTextColorsManager() noexcept;

        ConsoleTextColorsManager(const ConsoleTextColorsManager&) = default;
        ConsoleTextColorsManager& operator=(const ConsoleTextColorsManager&) = default;
        ConsoleTextColorsManager(ConsoleTextColorsManager&&) noexcept = default;
        ConsoleTextColorsManager& operator=(ConsoleTextColorsManager&&) noexcept = default;

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

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
