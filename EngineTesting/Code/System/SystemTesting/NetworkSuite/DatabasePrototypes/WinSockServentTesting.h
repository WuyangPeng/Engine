///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 14:24)

#ifndef SYSTEM_SECURITY_SUITE_WINSOCK_SERVENT_TESTING_H
#define SYSTEM_SECURITY_SUITE_WINSOCK_SERVENT_TESTING_H

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
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WINSOCK_SERVENT_TESTING_H