///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:36)

#include "StringDoubleMessageTesting.h"
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
using std::make_shared;
using std::string;

Network::StringDoubleMessageTesting::StringDoubleMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, StringDoubleMessageTesting)

void Network::StringDoubleMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = StringMessage<StringMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::StringDoubleMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::StringDoubleMessageTesting::RttiTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, fullMessageID, stringType) };
    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(fullMessageID) };

    ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ typeid(TestingType).name() });
}

void Network::StringDoubleMessageTesting::FactoryTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::UseSubId, fullMessageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ *buffer };
#include STSTEM_WARNING_POP
    testMessage->Save(messageTarget);

    MessageSource messageSource{ *buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int64_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::UseSubId, fullMessageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");

    ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(StringMessageField::Count));
    ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(stringType.size()), "消息大小错误！");

    for (auto i = 0u; i < stringType.size(); ++i)
    {
        ASSERT_EQUAL(stringType.at(i), polymorphicMessage->GetValue(System::UnderlyingCastEnum<StringMessageField>(i)));
    }

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

void Network::StringDoubleMessageTesting::StreamingTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::UseSubId, fullMessageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CoreTools::GetStreamSize(fullMessageID) + CoreTools::GetStreamSize(stringType) + 4);

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ *buffer };
#include STSTEM_WARNING_POP
    testMessage->Save(messageTarget);

    MessageSource messageSource{ *buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int64_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto sourceTestStringMessage{ make_shared<TestingType>(MessageHeadStrategy::UseSubId, fullMessageID, TestingType::StringType{}) };
    ASSERT_TRUE(sourceTestStringMessage->IsExactlyTypeOf(sourceTestStringMessage));

    sourceTestStringMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

void Network::StringDoubleMessageTesting::MessageTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::UseSubId, fullMessageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), subMessageID);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), fullMessageID);
}