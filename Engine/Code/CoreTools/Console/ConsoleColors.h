///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 15:24)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H

#include "ConsoleInstanceDetail.h"
#include "CoreTools/Contract/ContractFwd.h"

// 控制台显示颜色类
namespace CoreTools
{
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
        void SetTextColor(TextColour aTextColor);
        void SetTextIntensifiedColor(TextColour aTextColor);
        void SetBackgroundColor(BackgroundColour aBackgroundColor);
        void SetBackgroundIntensifiedColor(BackgroundColour aBackgroundColor);

    private:
        using ConsoleInstanceHandle = ConsoleInstance<Handle>;

    private:
        ConsoleInstanceHandle console;
        TextColour textColor;
        BackgroundColour backgroundColor;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H