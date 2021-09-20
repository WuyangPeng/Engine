///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/07 10:52)

#ifndef SYSTEM_SECURITY_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H
#define SYSTEM_SECURITY_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H

#include "System/Network/Fwd/NetworkFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSocketRecvFromTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSocketRecvFromTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSocketRecvFromTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RecvFromTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H