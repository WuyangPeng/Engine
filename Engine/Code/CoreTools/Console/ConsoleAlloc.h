///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:00)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
#define CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"

#include <cstdio>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ConsoleAlloc final
    {
    public:
        using ClassType = ConsoleAlloc;

    public:
        NODISCARD static ConsoleAlloc Create();

    private:
        explicit ConsoleAlloc(DisableNotThrow disableNotThrow);

    public:
        ~ConsoleAlloc() noexcept;

        ConsoleAlloc(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc& operator=(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc(ConsoleAlloc&& rhs) noexcept = delete;
        ConsoleAlloc& operator=(ConsoleAlloc&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void OpenConsole();
        void CloseConsole() const noexcept;

        void ReOpenConsole();
        static void CloseConsole(FILE* file) noexcept;

    private:
        FILE* out;
        FILE* in;
        FILE* error;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
