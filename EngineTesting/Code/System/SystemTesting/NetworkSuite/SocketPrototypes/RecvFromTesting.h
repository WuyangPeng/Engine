/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:04)

#ifndef SYSTEM_NETWORK_SUITE_RECV_FROM_TESTING_H
#define SYSTEM_NETWORK_SUITE_RECV_FROM_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class RecvFromTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = RecvFromTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit RecvFromTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RecvFromTest();

        void DoRecvFromTest(WinSocket socketHandle);
        NODISCARD WinSockInternetAddress BindInit(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_RECV_FROM_TESTING_H