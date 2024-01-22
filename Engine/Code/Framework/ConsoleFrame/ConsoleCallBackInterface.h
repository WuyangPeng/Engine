/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:19)

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
