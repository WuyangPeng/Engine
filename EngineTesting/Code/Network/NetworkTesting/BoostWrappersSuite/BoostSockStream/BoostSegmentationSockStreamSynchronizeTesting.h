///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 14:29)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamSynchronizeTesting final : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostSegmentationSockStreamSynchronizeTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostSegmentationSockStreamSynchronizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void StreamTest();

        void SynchronizeStreamTest();

        void ClientTest();
        void ServerTest();

        void ClientSynchronizeConnect(const TestingTypeSharedPtr& sockStream);
        void ClientSynchronizeSend(TestingType& sockStream);
        void ClientSynchronizeReceive(TestingType& sockStream);

        void ServerSynchronizeAcceptor(TestingType& sockStream);
        void ServerSynchronizeReceive(TestingType& sockStream);
        void ServerSynchronizeSend(TestingType& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H
