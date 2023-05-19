///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 14:29)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSegmentationSockStreamAsynchronousTesting final : public BoostSockStreamTesting
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
        void ClientAsynchronousSend(TestingType& sockStream);
        void ClientAsynchronousReceive(TestingType& sockStream);

        void ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream);
        void ServerAsynchronousReceive(TestingType& sockStream);
        void ServerAsynchronousSend(TestingType& sockStream);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SEGMENTATION_SOCK_STREAM_ASYNCHRONOUS_TESTING_H