/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:19)

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
