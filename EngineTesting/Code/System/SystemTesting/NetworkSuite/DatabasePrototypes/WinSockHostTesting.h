///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/07 22:32)

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