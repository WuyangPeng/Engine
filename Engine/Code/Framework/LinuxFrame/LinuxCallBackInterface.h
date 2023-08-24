///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:52)

#ifndef FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H
#define FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE LinuxCallBackInterface
    {
    public:
        using ClassType = LinuxCallBackInterface;

    public:
        LinuxCallBackInterface() noexcept = default;
        virtual ~LinuxCallBackInterface() noexcept = default;
        LinuxCallBackInterface(const LinuxCallBackInterface& rhs) noexcept = default;
        LinuxCallBackInterface& operator=(const LinuxCallBackInterface& rhs) noexcept = default;
        LinuxCallBackInterface(LinuxCallBackInterface&& rhs) noexcept = default;
        LinuxCallBackInterface& operator=(LinuxCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H
