///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 14:29)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamNonBlockingTesting final : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostSegmentationSockStreamNonBlockingTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostSegmentationSockStreamNonBlockingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void StreamTest();

        void NonBlockingStreamTest();

        void ClientTest();
        void ServerTest();

        void ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream);
        void ClientNonBlockingSend(TestingType& sockStream);
        void ClientNonBlockingReceive(TestingType& sockStream);

        void ServerNonBlockingAcceptor(TestingType& sockStream);
        void ServerNonBlockingReceive(TestingType& sockStream);
        void ServerNonBlockingSend(TestingType& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H