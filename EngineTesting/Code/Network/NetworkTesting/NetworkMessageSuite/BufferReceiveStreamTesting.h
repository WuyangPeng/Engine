///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:21)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class BufferReceiveStreamTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferReceiveStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferReceiveStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ReceiveTest(int aTestLoopCount);
        void FinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void UnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void CopyFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void CopyUnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy);

        NODISCARD MessageBufferSharedPtr CreateAddMessageBuffer(ParserStrategy parserStrategy) const;
        NODISCARD MessageBufferSharedPtr CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy) const;
        void AddBufferLength(MessageBuffer& messageBuffer);

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
        uint64_t socketID;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H