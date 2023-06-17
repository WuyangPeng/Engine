///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:41)

#ifndef FRAMEWORK_LINUX_LINUX_PROCESS_H
#define FRAMEWORK_LINUX_LINUX_PROCESS_H

#include "LinuxCallBackInterface.h"

#include <type_traits>

namespace Framework
{
    template <typename LinuxCallBack>
    class LinuxProcess
    {
    public:
        static_assert(std::is_base_of_v<LinuxCallBackInterface, LinuxCallBack>);

    public:
        using CallBackType = LinuxCallBack;
        using ClassType = LinuxProcess<CallBackType>;
        using LinuxCallBackInterfaceSharedPtr = std::shared_ptr<LinuxCallBackInterface>;

    public:
        LinuxProcess() = default;
        virtual ~LinuxProcess() noexcept = default;
        LinuxProcess(const LinuxProcess& rhs) noexcept = default;
        LinuxProcess& operator=(const LinuxProcess& rhs) noexcept = default;
        LinuxProcess(LinuxProcess&& rhs) noexcept = default;
        LinuxProcess& operator=(LinuxProcess&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };

    using LinuxProcessInterface = LinuxProcess<LinuxCallBackInterface>;
}

#endif  // FRAMEWORK_LINUX_LINUX_PROCESS_H
