///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:09)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamAsynchronousTesting : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostSegmentationSockStreamAsynchronousTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostSegmentationSockStreamAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void StreamTest();

        void AsynchronousStreamTest();

        void ClientTest();
        void ServerTest();

        void ClientAsynchronousConnect(const TestingTypeSharedPtr& sockStream);
        void ClientAsynchronousSend(const TestingTypeSharedPtr& sockStream);
        void ClientAsynchronousReceive(const TestingTypeSharedPtr& sockStream);

        void ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream);
        void ServerAsynchronousReceive(const TestingTypeSharedPtr& sockStream);
        void ServerAsynchronousSend(const TestingTypeSharedPtr& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H