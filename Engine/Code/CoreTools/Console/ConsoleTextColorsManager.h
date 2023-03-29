///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 10:44)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
#define CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H

#include "ConsoleColorsDetail.h"

// ����̨��ɫ����
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

        ConsoleTextColorsManager(const ConsoleTextColorsManager& rhs) noexcept = default;
        ConsoleTextColorsManager& operator=(const ConsoleTextColorsManager& rhs) noexcept = default;
        ConsoleTextColorsManager(ConsoleTextColorsManager&& rhs) noexcept = default;
        ConsoleTextColorsManager& operator=(ConsoleTextColorsManager&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

    private:
        void SetTextColor();
        void ResetTextColor();

    private:
        using ConsoleColorsHandle = ConsoleColors<Handle>;

    private:
        ConsoleColorsHandle consoleColors;
        TextColour textColor;
        bool intensified;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_TEXT_COLOR_MANAGER_H
