///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/10 21:44)

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
        void DoRunUnitTest() final;
        void MainTest();

        void RecvFromTest();

        void DoRecvFromTest(WinSocket socketHandle);
        NODISCARD WinSockInternetAddress BindInit(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_RECV_FROM_TESTING_H