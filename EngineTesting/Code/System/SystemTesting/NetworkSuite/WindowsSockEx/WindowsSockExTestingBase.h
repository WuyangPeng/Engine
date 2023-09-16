///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:33)

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
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINDOWS_SOCK_EX_TESTING_BASE_H