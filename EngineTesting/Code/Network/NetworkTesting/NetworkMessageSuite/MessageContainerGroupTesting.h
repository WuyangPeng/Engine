///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 09:58)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_CONTAINER_GROUP_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_CONTAINER_GROUP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageContainerGroupTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageContainerGroupTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageContainerGroupTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void BaseTest();
        void StreamingTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_CONTAINER_GROUP_TESTING_H