///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 15:06)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SEND_MESSAGE_LEVEL_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SEND_MESSAGE_LEVEL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class SendMessageLevelTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SendMessageLevelTesting;
        using ParentType = UnitTest;

    public:
        explicit SendMessageLevelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SendMessageTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SEND_MESSAGE_LEVEL_TESTING_H