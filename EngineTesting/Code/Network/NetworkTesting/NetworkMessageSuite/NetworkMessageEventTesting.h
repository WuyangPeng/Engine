///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:40)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NETWORK_MESSAGE_EVENT_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NETWORK_MESSAGE_EVENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class NetworkMessageEventTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = NetworkMessageEventTesting;
        using ParentType = UnitTest;

    public:
        explicit NetworkMessageEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EventTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NETWORK_MESSAGE_EVENT_TESTING_H