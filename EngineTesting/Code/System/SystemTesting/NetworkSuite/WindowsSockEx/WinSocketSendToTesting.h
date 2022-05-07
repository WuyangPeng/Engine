///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 10:52)

#ifndef SYSTEM_SECURITY_SUITE_WIN_SOCKET_SEND_TO_TESTING_H
#define SYSTEM_SECURITY_SUITE_WIN_SOCKET_SEND_TO_TESTING_H

#include "System/Network/Fwd/NetworkFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSocketSendToTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSocketSendToTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSocketSendToTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SendToTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WIN_SOCKET_SEND_TO_TESTING_H