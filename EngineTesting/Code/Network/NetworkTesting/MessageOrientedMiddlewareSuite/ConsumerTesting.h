///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 17:03)

#ifndef NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_CONSUMER_TESTING_H
#define NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_CONSUMER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ConsumerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsumerTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsumerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void ConsumerTest();

    private:
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_CONSUMER_TESTING_H