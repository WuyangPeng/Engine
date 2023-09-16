///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:33)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ReceiveMessageLevelTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReceiveMessageLevelTesting;
        using ParentType = UnitTest;

    public:
        explicit ReceiveMessageLevelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ReceiveMessageTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H