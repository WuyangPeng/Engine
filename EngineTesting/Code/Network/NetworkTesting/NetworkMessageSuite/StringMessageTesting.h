///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 08:57)

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
        void DoRunUnitTest() override;

        void RttiTest();
        void FactoryTest();
        void StreamingTest();
        void MessageTest();

    private:
        static constexpr auto messageId = 6LL;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H