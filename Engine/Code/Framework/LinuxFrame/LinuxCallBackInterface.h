/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:17)

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
