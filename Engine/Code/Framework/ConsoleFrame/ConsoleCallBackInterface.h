///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:42)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H
#define FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ConsoleCallBackInterface
    {
    public:
        using ClassType = ConsoleCallBackInterface;

    public:
        ConsoleCallBackInterface() noexcept = default;
        virtual ~ConsoleCallBackInterface() noexcept = default;
        ConsoleCallBackInterface(const ConsoleCallBackInterface& rhs) noexcept = default;
        ConsoleCallBackInterface& operator=(const ConsoleCallBackInterface& rhs) noexcept = default;
        ConsoleCallBackInterface(ConsoleCallBackInterface&& rhs) noexcept = default;
        ConsoleCallBackInterface& operator=(ConsoleCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H
