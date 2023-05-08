///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:43)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class StringMessageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = StringMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit StringMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void RttiTest();
        void FactoryTest();
        void StreamingTest();
        void MessageTest();

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H