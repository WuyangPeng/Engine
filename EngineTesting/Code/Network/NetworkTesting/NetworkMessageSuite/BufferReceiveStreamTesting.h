///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:21)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class BufferReceiveStreamTesting final : public CoreTools::UnitTest
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
        NODISCARD MessageBufferSharedPtr CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy);
        void AddBufferLength(MessageBuffer& messageBuffer);

        void DoRunUnitTest() override;

    private:
        static constexpr auto messageId = 6LL;
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
        int64_t socketId;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H