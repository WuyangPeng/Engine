///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:47)

#include "MessageContainerTesting.h"
#include "Flags/IntegerMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageContainerDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::MessageContainerTesting::MessageContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageContainerTesting)

void Network::MessageContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = MessageContainer<IntegerMessageField, int64_t>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::MessageContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MessageContainerTesting::BaseTest()
{
    const TestingType::MessageType message{ 100, 10, 10000, 5, 100 };
    const TestingType messageContainer{ message };

    ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), boost::numeric_cast<int>(message.size()), "数组大小不相等！");

    for (auto i = 0; i < messageContainer.GetSize(); ++i)
    {
        ASSERT_EQUAL(message.at(i), messageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
    }
}

void Network::MessageContainerTesting::StreamingTest()
{
    const TestingType::MessageType message{ 100, 10, 1000, 2, 100 };
    const TestingType messageContainer{ message };

    ASSERT_EQUAL(messageContainer.GetStreamingSize(), CoreTools::GetStreamSize(message));

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };

    MessageTarget messageTarget{ buffer };

    messageContainer.Save(messageTarget);

    MessageSource messageSource{ buffer };

    TestingType resultMessageContainer{};

    resultMessageContainer.Load(messageSource);

    ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), resultMessageContainer.GetSize(), "数组大小不相等！");

    for (auto i = 0; i < messageContainer.GetSize(); ++i)
    {
        ASSERT_EQUAL(resultMessageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)), messageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
    }
}