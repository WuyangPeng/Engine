/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:03)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCK_HOST_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCK_HOST_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void GetHostByAddressTest();
        void GetHostNameTest();

        void WinSockHostEntTest(const WinSockHostEnt* winSockHostEnt);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCK_HOST_TESTING_H