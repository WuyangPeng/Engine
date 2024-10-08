/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:05)

#ifndef SYSTEM_NETWORK_SUITE_WINDOWS_SOCK_EX_TESTING_BASE_H
#define SYSTEM_NETWORK_SUITE_WINDOWS_SOCK_EX_TESTING_BASE_H

#include "System/SystemTesting/NetworkSuite/NetworkTestingBase.h"

namespace System
{
    class WindowsSockExTestingBase : public NetworkTestingBase
    {
    public:
        using ClassType = WindowsSockExTestingBase;
        using ParentType = NetworkTestingBase;

    public:
        explicit WindowsSockExTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD String GetConnectHostname() const;
        NODISCARD uint16_t GetConnectPort() const;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINDOWS_SOCK_EX_TESTING_BASE_H