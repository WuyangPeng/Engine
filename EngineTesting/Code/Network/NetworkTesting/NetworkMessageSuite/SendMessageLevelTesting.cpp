///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:52)

#include "SendMessageLevelTesting.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/SendMessageLevel.h"

Network::SendMessageLevelTesting::SendMessageLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SendMessageLevelTesting)

void Network::SendMessageLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SendMessageLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendMessageTest);
}

void Network::SendMessageLevelTesting::SendMessageTest()
{
    const auto bufferSize = 8 * GetTestLoopCount();
    SendMessageLevel sendMessageLevel{ bufferSize };

    ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize);

    constexpr auto messageId = 6LL;
    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        sendMessageLevel.Insert(testMessage);

        ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), i + 1);
        ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), testMessage->GetStreamingSize() * (i + 1));
        ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize - testMessage->GetStreamingSize() * (i + 1));

        ASSERT_EQUAL(sendMessageLevel[i], testMessage);
    }

    sendMessageLevel.Clear();

    ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize);
}
