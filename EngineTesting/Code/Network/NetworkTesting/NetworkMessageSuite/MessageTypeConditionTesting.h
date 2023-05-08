///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:35)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageTypeConditionTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageTypeConditionTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageTypeConditionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void CompareTest();
        void RangeTest();
        void SpecificTest();
        void AllTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_TESTING_H