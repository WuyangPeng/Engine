///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:28)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class BufferSendStreamTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferSendStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferSendStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void SendTest(int aTestLoopCount);
        void FinishSendTest(int aTestLoopCount, ParserStrategy parserStrategy);

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H