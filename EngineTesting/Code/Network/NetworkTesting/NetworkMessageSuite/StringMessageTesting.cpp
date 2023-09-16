///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:52)

#include "StringMessageTesting.h"
#include "Flags/StringMessageType.h"
#include "Detail/TestIntMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/StringMessageDetail.h"

Network::StringMessageTesting::StringMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, StringMessageTesting)

void Network::StringMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = StringMessage<StringMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::StringMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::StringMessageTesting::RttiTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, stringType);
    const auto testIntMessage = std::make_shared<TestIntMessage>(messageId);

    ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), typeid(TestingType).name());
}

void Network::StringMessageTesting::FactoryTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, stringType);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::Default, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");

    ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(StringMessageField::Count));
    ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(stringType.size()), "消息大小错误！");

    for (auto i = 0u; i < stringType.size(); ++i)
    {
        ASSERT_EQUAL(stringType.at(i), polymorphicMessage->GetValue(System::UnderlyingCastEnum<StringMessageField>(i)));
    }

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::StringMessageTesting::StreamingTest()
{
    const TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, stringType);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CoreTools::GetStreamSize(messageId) + CoreTools::GetStreamSize(stringType));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto sourceTestStringMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, TestingType::StringType{});
    ASSERT_TRUE(sourceTestStringMessage->IsExactlyTypeOf(sourceTestStringMessage));

    sourceTestStringMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::StringMessageTesting::MessageTest()
{
    const TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, stringType);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageId);
}
