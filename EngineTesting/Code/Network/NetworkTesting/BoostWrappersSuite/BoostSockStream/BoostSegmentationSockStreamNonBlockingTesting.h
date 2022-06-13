///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamNonBlockingTesting : public BoostSockStreamTesting
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
        void ClientNonBlockingSend(const TestingTypeSharedPtr& sockStream);
        void ClientNonBlockingReceive(const TestingTypeSharedPtr& sockStream);

        void ServerNonBlockingAcceptor(const TestingTypeSharedPtr& sockStream);
        void ServerNonBlockingReceive(const TestingTypeSharedPtr& sockStream);
        void ServerNonBlockingSend(const TestingTypeSharedPtr& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_NON_BLOCKING_TESTING_H