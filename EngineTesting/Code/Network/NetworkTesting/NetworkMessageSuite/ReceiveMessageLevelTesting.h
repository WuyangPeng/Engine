///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:42)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ReceiveMessageLevelTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReceiveMessageLevelTesting;
        using ParentType = UnitTest;

    public:
        explicit ReceiveMessageLevelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ReceiveMessageTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H