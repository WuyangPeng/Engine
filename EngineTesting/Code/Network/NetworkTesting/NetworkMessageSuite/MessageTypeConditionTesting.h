///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:31)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageTypeConditionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageTypeConditionTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageTypeConditionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void CompareTest();
        void RangeTest();
        void SpecificTest();
        void AllTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H