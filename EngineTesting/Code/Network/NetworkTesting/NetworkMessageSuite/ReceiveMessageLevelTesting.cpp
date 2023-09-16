///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:52)

#include "ReceiveMessageLevelTesting.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/ReceiveMessageLevel.h"

Network::ReceiveMessageLevelTesting::ReceiveMessageLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ReceiveMessageLevelTesting)

void Network::ReceiveMessageLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ReceiveMessageLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReceiveMessageTest);
}

void Network::ReceiveMessageLevelTesting::ReceiveMessageTest()
{
    ReceiveMessageLevel receiveMessageLevel = ReceiveMessageLevel::Create();

    ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), 0);

    constexpr auto messageId = 6LL;
    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        receiveMessageLevel.Insert(testMessage);

        ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), i + 1);

        ASSERT_EQUAL(receiveMessageLevel[i], testMessage);
    }
}
