// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.4 (2020/03/12 14:54)

#include "StringMessageTesting.h"
#include "Flags/StringMessageType.h"
#include "Detail/TestIntMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/StringMessageDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, StringMessageTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
namespace Network
{
    using TestingType = StringMessage<StringMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::StringMessageTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    //ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    // ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::StringMessageTesting ::RttiTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, stringType) };
    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

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

void Network::StringMessageTesting ::FactoryTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, stringType) };

    MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, sm_MessageID);

    auto factoryCreateMessage = TestingType::Factory(*messageSource, sm_MessageID);
    // 	auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestingType>(factoryCreateMessage);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");
    //
    // 	ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(StringMessageField::Count));
    // 	ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(stringType.size()), "消息大小错误！");
    //
    // 	for (auto i = 0u; i < stringType.size(); ++i)
    // 	{
    // 		ASSERT_EQUAL(stringType[i], polymorphicMessage->GetValue(System::UnderlyingCastEnum<StringMessageField>(i)));
    // 	}
    //
    // 	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::StringMessageTesting ::StreamingTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, stringType) };

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_MessageID) + CORE_TOOLS_STREAM_SIZE(stringType));

    MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, sm_MessageID);

    auto sourceTestStringMessage{ make_shared<TestingType>(sm_MessageID, TestingType::StringType{}) };

    sourceTestStringMessage->Load(*messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::StringMessageTesting ::MessageTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, stringType) };

    ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
    ASSERT_EQUAL(testMessage->GetSubMessageID(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_MessageID);
}
#include STSTEM_WARNING_POP