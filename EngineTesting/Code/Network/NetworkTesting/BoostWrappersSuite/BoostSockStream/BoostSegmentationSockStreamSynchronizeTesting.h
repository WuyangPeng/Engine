///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H

#include "System/Helper/Platform.h"
#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamSynchronizeTesting : public BoostSockStreamTesting
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
        void ClientSynchronizeSend(const TestingTypeSharedPtr& sockStream);
        void ClientSynchronizeReceive(const TestingTypeSharedPtr& sockStream);

        void ServerSynchronizeAcceptor(const TestingTypeSharedPtr& sockStream);
        void ServerSynchronizeReceive(const TestingTypeSharedPtr& sockStream);
        void ServerSynchronizeSend(const TestingTypeSharedPtr& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_SYNCHRONIZE_TESTING_H
