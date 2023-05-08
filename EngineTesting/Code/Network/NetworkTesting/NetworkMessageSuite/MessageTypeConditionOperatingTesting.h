///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:35)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageTypeConditionOperatingTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageTypeConditionOperatingTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageTypeConditionOperatingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void OperatingTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H