///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:28)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class BufferSendStreamTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferSendStreamTesting);

    private:
        void MainTest();

        void SendTest(int testLoopCount);
        void FinishSendTest(int testLoopCount, ParserStrategy parserStrategy);

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H