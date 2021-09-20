///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 18:46)

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
        explicit ConsoleInstance(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConsoleHandle GetHandle() noexcept;

    private:
        ConsoleHandle handle;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H