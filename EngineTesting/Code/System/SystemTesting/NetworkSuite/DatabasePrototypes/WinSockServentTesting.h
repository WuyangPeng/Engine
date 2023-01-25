///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/07 22:48)

#ifndef SYSTEM_NETWORK_SUITE_WINSOCK_SERVENT_TESTING_H
#define SYSTEM_NETWORK_SUITE_WINSOCK_SERVENT_TESTING_H

#include "System/Network/Using/DatabasePrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSockServentTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSockServentTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSockServentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetServentTest();

        void WinSockServentTest(const WinSockServent* winSockServent);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINSOCK_SERVENT_TESTING_H