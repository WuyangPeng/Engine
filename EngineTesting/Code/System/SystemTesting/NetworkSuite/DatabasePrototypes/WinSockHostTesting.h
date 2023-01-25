///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/07 22:32)

#ifndef SYSTEM_NETWORK_SUITE_WINSOCK_HOST_TESTING_H
#define SYSTEM_NETWORK_SUITE_WINSOCK_HOST_TESTING_H

#include "System/Network/Using/DatabasePrototypesUsing.h"
#include "System/SystemTesting/NetworkSuite/NetworkTestingBase.h"

namespace System
{
    class WinSockHostTesting final : public NetworkTestingBase
    {
    public:
        using ClassType = WinSockHostTesting;
        using ParentType = NetworkTestingBase;

    public:
        explicit WinSockHostTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetHostByAddressTest();
        void GetHostNameTest();

        void WinSockHostentTest(const WinSockHostent* winSockHostent);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINSOCK_HOST_TESTING_H