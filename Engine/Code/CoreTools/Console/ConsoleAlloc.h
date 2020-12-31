//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 15:12)

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
        explicit ConsoleAlloc(DisableNotThrow disableNotThrow);
        ~ConsoleAlloc() noexcept;

        ConsoleAlloc(const ConsoleAlloc&) = delete;
        ConsoleAlloc& operator=(const ConsoleAlloc&) = delete;
        ConsoleAlloc(ConsoleAlloc&&) noexcept = delete;
        ConsoleAlloc& operator=(ConsoleAlloc&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void OpenConsole();
        void CloseConsole() noexcept;

    private:
        FILE* m_Out;
        FILE* m_In;
        FILE* m_Error;
    };
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
