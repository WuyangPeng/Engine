///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:30)

#ifndef SYSTEM_NETWORK_SUITE_CONNECT_TESTING_H
#define SYSTEM_NETWORK_SUITE_CONNECT_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class ConnectTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = ConnectTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit ConnectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConnectTest();

        void DoConnectTest(WinSocket socketHandle);
        void SendTest(WinSocket socketHandle);
        void RecvTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_CONNECT_TESTING_H