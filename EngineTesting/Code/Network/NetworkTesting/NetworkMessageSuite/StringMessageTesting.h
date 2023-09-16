///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:33)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class StringMessageTesting final : public CoreTools::UnitTest
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