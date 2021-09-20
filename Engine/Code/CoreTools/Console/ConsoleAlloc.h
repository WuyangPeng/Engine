///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 19:02)

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
        explicit ConsoleAlloc(MAYBE_UNUSED DisableNotThrow disableNotThrow);
        ~ConsoleAlloc() noexcept;

        ConsoleAlloc(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc& operator=(const ConsoleAlloc& rhs) = delete;
        ConsoleAlloc(ConsoleAlloc&& rhs) noexcept = delete;
        ConsoleAlloc& operator=(ConsoleAlloc&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void OpenConsole();
        void CloseConsole() noexcept;

        void ReOpenConsole();
        void CloseConsole(FILE* file) noexcept;

    private:
        FILE* out;
        FILE* in;
        FILE* error;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
