///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:13)

#ifndef SYSTEM_NETWORK_SUITE_DATABASE_WIN_SOCK_PROTO_ENT_TESTING_H
#define SYSTEM_NETWORK_SUITE_DATABASE_WIN_SOCK_PROTO_ENT_TESTING_H

#include "System/Network/Using/DatabasePrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSockProtoEntTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSockProtoEntTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSockProtoEntTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetProtoEntTest();

        void WinSockProtoEntTest(const WinSockProtoEnt* winSockProtoEnt);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_DATABASE_WIN_SOCK_PROTO_ENT_TESTING_H