///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:42)

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
