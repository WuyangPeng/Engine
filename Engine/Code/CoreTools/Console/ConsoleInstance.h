/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:36)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H

#include "Flags/ConsoleColorsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Contract/ContractFwd.h"

namespace CoreTools
{
    template <StandardHandle Handle>
    class ConsoleInstance final
    {
    public:
        using ClassType = ConsoleInstance;

        using ConsoleHandle = System::WindowsHandle;

    public:
        NODISCARD static ConsoleInstance Create();

    private:
        explicit ConsoleInstance(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD ConsoleHandle GetHandle() const noexcept;

    private:
        ConsoleHandle handle;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H