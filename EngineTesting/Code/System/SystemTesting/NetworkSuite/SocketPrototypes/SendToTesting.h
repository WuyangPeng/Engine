///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/10 22:57)

#ifndef SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H
#define SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class SendToTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = SendToTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit SendToTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SendToTest();

        void DoSendToTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H