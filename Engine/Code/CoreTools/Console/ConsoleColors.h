///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/11 14:52)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H

#include "ConsoleInstanceDetail.h"
#include "CoreTools/Contract/ContractFwd.h"

namespace CoreTools
{
    // 控制台显示颜色类
    template <StandardHandle Handle>
    class ConsoleColors final
    {
    public:
        using ClassType = ConsoleColors<Handle>;

    public:
        NODISCARD static ConsoleColors Create();

    private:
        explicit ConsoleColors(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void ResetColor();
        void SetTextColor(TextColour textColor);
        void SetTextIntensifiedColor(TextColour textColor);
        void SetBackgroundColor(BackgroundColour backgroundColor);
        void SetBackgroundIntensifiedColor(BackgroundColour backgroundColor);

    private:
        using ConsoleInstanceHandle = ConsoleInstance<Handle>;

    private:
        ConsoleInstanceHandle console;
        TextColour m_TextColor;
        BackgroundColour m_BackgroundColor;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H