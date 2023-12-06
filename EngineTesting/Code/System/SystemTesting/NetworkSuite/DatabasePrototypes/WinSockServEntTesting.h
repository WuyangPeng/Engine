///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:23)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCK_SERV_ENT_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCK_SERV_ENT_TESTING_H

#include "System/Network/Using/DatabasePrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSockServEntTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSockServEntTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSockServEntTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetServEntTest();

        void WinSockServEntTest(const WinSockServEnt* winSockServEnt);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCK_SERV_ENT_TESTING_H