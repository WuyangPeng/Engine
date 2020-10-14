//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 15:12)

// ����̨��ʾ��ɫ��
#ifndef CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H
#define CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H

#include "ConsoleInstanceDetail.h"
#include "CoreTools/Contract/ContractFwd.h"

namespace CoreTools
{
    template <StandardHandle Handle>
    class ConsoleColors final
    {
    public:
        using ClassType = ConsoleColors<Handle>;

    public:
        explicit ConsoleColors(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void ResetColor();
        void SetTextColor(TextColour textColor);
        void SetTextIntensifiedColor(TextColour textColor);
        void SetBackgroundColor(BackgroundColour backgroundColor);
        void SetBackgroundIntensifiedColor(BackgroundColour backgroundColor);

    private:
        using ConsoleInstanceHandle = ConsoleInstance<Handle>;

    private:
        ConsoleInstanceHandle m_Console;
        TextColour m_TextColor;
        BackgroundColour m_BackgroundColor;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_COLORS_H