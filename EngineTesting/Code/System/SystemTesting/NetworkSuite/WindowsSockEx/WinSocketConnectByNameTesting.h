///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 10:52)

#ifndef SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H
#define SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSocketConnectByNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSocketConnectByNameTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSocketConnectByNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConnectTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H