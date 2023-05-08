///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:41)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class NullMessageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = NullMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit NullMessageTesting(const OStreamShared& stream);

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

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_MESSAGE_TESTING_H