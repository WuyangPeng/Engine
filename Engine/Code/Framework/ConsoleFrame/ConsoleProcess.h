/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:19)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H
#define FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H

#include "ConsoleCallBackInterface.h"

#include <memory>
#include <type_traits>

namespace Framework
{
    template <typename ConsoleCallBack>
    class ConsoleProcess
    {
    public:
        static_assert(std::is_base_of_v<ConsoleCallBackInterface, ConsoleCallBack>);

    public:
        using CallBackType = ConsoleCallBack;
        using ClassType = ConsoleProcess<CallBackType>;

        using ConsoleCallBackInterfaceSharedPtr = std::shared_ptr<ConsoleCallBackInterface>;

    public:
        ConsoleProcess() = default;
        virtual ~ConsoleProcess() noexcept = default;
        ConsoleProcess(const ConsoleProcess& rhs) noexcept = default;
        ConsoleProcess& operator=(const ConsoleProcess& rhs) noexcept = default;
        ConsoleProcess(ConsoleProcess&& rhs) noexcept = default;
        ConsoleProcess& operator=(ConsoleProcess&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };

    using ConsoleProcessInterface = ConsoleProcess<ConsoleCallBackInterface>;
}

#endif  // FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H
