/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 14:58)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H

#include "CoreTools/CoreToolsDll.h"

#include "ConsoleInstance.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Contract/ContractFwd.h"

/// ����̨��ʾ��ɫ��
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
        explicit ConsoleColors(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void ResetColor();
        void SetTextColor(TextColour aTextColor);
        void SetTextIntensifiedColor(TextColour aTextColor);
        void SetBackgroundColor(BackgroundColour aBackgroundColor);
        void SetBackgroundIntensifiedColor(BackgroundColour aBackgroundColor);

    private:
        using ConsoleInstanceHandle = ConsoleInstance<Handle>;

        static constexpr auto defaultTextColor = TextColour::White;
        static constexpr auto defaultBackgroundColor = BackgroundColour::Black;

    private:
        ConsoleInstanceHandle console;
        TextColour textColor;
        BackgroundColour backgroundColor;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H