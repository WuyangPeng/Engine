/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:36)

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