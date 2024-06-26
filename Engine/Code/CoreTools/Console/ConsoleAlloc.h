/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:58)

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

        ~ConsoleAlloc() noexcept;
        ConsoleAlloc(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc& operator=(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc(ConsoleAlloc&& rhs) noexcept = delete;
        ConsoleAlloc& operator=(ConsoleAlloc&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        explicit ConsoleAlloc(DisableNotThrow disableNotThrow);

        void OpenConsole();
        void CloseConsole() const noexcept;

        void ReOpenConsole();
        static void LogWait();
        static void CloseConsole(FILE* file) noexcept;

    private:
        FILE* out;
        FILE* in;
        FILE* error;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
