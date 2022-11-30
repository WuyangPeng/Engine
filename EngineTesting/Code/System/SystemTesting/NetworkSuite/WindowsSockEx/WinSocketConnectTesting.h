///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/03 22:00)

#ifndef SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_TESTING_H
#define SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSocketConnectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSocketConnectTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSocketConnectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConnectTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_TESTING_H