///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 16:16)

#include "JsonMessageTesting.h"
#include "Detail/TestJsonMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/JsonMessageDetail.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

using System::operator|;

namespace Network
{
    using TestingType = JsonMessage<TestJsonMessage>;
}

Network::JsonMessageTesting::JsonMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, JsonMessageTesting)

void Network::JsonMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::JsonMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::JsonMessageTesting::RttiTest()
{
    const auto testJsonMessage = std::make_shared<TestingType>(MessageHeadStrategy::UseJson, messageId, "TestingType");
    const auto testMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);

    ASSERT_TRUE(testJsonMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testJsonMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testJsonMessage->IsDerived(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testJsonMessage->IsDerived(NullMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testJsonMessage->IsExactlyTypeOf(testJsonMessage));
    ASSERT_TRUE(testJsonMessage->IsDerivedTypeOf(testJsonMessage));

    ASSERT_FALSE(testJsonMessage->IsExactlyTypeOf(testMessage));
    ASSERT_FALSE(testJsonMessage->IsDerivedTypeOf(testMessage));

    const auto& attiType = testJsonMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), "class Network::TestJsonMessage");
}

void Network::JsonMessageTesting::FactoryTest()
{
    const TestingType testJsonMessage{ MessageHeadStrategy::UseJson, messageId, "TestingType" };

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testJsonMessage.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::UseJson, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    const auto result = polymorphicMessage->GetJsonMessage();

    ASSERT_EQUAL(result.GetJsonMessage(), "TestingType");

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::JsonMessageTesting::StreamingTest()
{
    const std::string message{ "TestingType" };
    const auto testJsonMessage = std::make_shared<TestingType>(MessageHeadStrategy::UseJson | MessageHeadStrategy::UseSubId, fullMessageId, message);

    ASSERT_TRUE(testJsonMessage->IsExactlyTypeOf(testJsonMessage));

    ASSERT_EQUAL(testJsonMessage->GetStreamingSize(), 12 + CoreTools::GetStreamSize(message));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testJsonMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int64_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, fullMessageId);

    const auto sourcePlayerResponse = std::make_shared<TestingType>(MessageHeadStrategy::UseJson | MessageHeadStrategy::UseSubId, fullMessageId, "");
    ASSERT_TRUE(sourcePlayerResponse->IsExactlyTypeOf(sourcePlayerResponse));

    sourcePlayerResponse->Load(messageSource);

    ASSERT_EQUAL(sourcePlayerResponse->GetJsonMessage().GetJsonMessage(), message);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::JsonMessageTesting::MessageTest()
{
    const auto testJsonMessage = std::make_shared<TestingType>(MessageHeadStrategy::UseJson | MessageHeadStrategy::UseSubId, fullMessageId, "message");

    ASSERT_EQUAL(testJsonMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testJsonMessage->GetSubMessageId(), subMessageId);
    ASSERT_EQUAL(testJsonMessage->GetFullMessageId(), fullMessageId);

    ASSERT_TRUE(testJsonMessage->IsExactlyTypeOf(testJsonMessage));

    ASSERT_ENUM_EQUAL(testJsonMessage->GetMessageHeadStrategy(), MessageHeadStrategy::UseJson | MessageHeadStrategy::UseSubId);
}
