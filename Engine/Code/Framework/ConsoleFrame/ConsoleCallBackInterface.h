///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:52)

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
