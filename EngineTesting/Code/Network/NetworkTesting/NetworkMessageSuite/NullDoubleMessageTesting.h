///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:32)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class NullDoubleMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NullDoubleMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit NullDoubleMessageTesting(const OStreamShared& stream);

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
        static constexpr auto subMessageId = 4LL;
        static constexpr auto fullMessageId = (messageId << 32LL) + subMessageId;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H