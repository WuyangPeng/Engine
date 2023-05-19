///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 14:43)

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