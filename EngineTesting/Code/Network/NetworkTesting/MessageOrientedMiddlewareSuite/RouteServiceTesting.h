///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/19 09:12)

#ifndef NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_ROUTE_SERVICE_TESTING_H
#define NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_ROUTE_SERVICE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/MessageOrientedMiddleware/MessageOrientedMiddlewareFwd.h"

namespace Network
{
    class RouteServiceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RouteServiceTesting;
        using ParentType = UnitTest;

    public:
        explicit RouteServiceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void ConsumerTest();
        void ConsumerExceptionTest(const RouteService& routeService);
        void BroadcastMessageTest();

    private:
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_MESSAGE_ORIENTED_MIDDLEWARE_SUITE_ROUTE_SERVICE_TESTING_H