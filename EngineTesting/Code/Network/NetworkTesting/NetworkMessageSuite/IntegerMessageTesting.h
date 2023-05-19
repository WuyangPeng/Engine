///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 08:55)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class IntegerMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = IntegerMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit IntegerMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RttiTest();
        void FactoryTest();
        void StreamingTest();
        void MessageTest();

    private:
        static constexpr auto messageId = 6LL;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H