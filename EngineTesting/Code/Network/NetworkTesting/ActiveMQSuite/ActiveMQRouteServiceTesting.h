///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:13)

#ifndef NETWORK_TESTING_ACTIVE_MQ_SUITE_ACTIVE_MQ_ROUTE_SERVICE_TESTING_H
#define NETWORK_TESTING_ACTIVE_MQ_SUITE_ACTIVE_MQ_ROUTE_SERVICE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class ActiveMQRouteServiceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ActiveMQRouteServiceTesting;
        using ParentType = UnitTest;

    public:
        explicit ActiveMQRouteServiceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void BroadcastMessageTest();

        void CreateMessage();
        void DestroyMessage();

    private:
        int messageId;
    };
}

#endif  // NETWORK_TESTING_ACTIVE_MQ_SUITE_ACTIVE_MQ_ROUTE_SERVICE_TESTING_H