// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/12 13:31)

#include "IntegerDoubleMessageTesting.h" 
#include "Detail/TestIntMessage.h"
#include "Flags/IntegerMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/IntegerDoubleMessageDetail.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, IntegerDoubleMessageTesting)

namespace Network
{
	using TestingType = IntegerDoubleMessage<IntegerMessageField>;
	using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::IntegerDoubleMessageTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::IntegerDoubleMessageTesting
	::RttiTest()
{
	TestingType::IntegerType integerType{ 100,10,1000,2,100 };

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_FullMessageID,integerType) };
	TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_FullMessageID) };

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

void Network::IntegerDoubleMessageTesting
	::FactoryTest()
{
	TestingType::IntegerType integerType{ 100,10,1000,2,100 };

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_FullMessageID,integerType) };

	MESSAGE_MANAGER_SINGLETON.Insert(sm_FullMessageID, MessageTypeCondition{}, TestingType::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_FullMessageID);

	auto factoryCreateMessage = TestingType::Factory(messageSource, sm_FullMessageID);
	//auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestingType>(factoryCreateMessage);

	//ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");

// 	ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(IntegerMessageField::Count));
// 	ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(integerType.size()), "消息大小错误！");
// 
// 	for (auto i = 0u; i < integerType.size(); ++i)
// 	{
// 		ASSERT_EQUAL(integerType[i], polymorphicMessage->GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
// 	}
// 
// 	MESSAGE_MANAGER_SINGLETON.Remove(sm_FullMessageID);
}

void Network::IntegerDoubleMessageTesting
	::StreamingTest()
{
	TestingType::IntegerType integerType{ 100,10,1000,2,100 };

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_FullMessageID,integerType) };

	ASSERT_EQUAL(testMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_FullMessageID) + CORE_TOOLS_STREAM_SIZE(integerType));

	MESSAGE_MANAGER_SINGLETON.Insert(sm_FullMessageID, MessageTypeCondition{}, TestingType::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_FullMessageID);

	auto sourceTestIntMessage{ make_shared<TestingType>(sm_FullMessageID,TestingType::IntegerType{ }) };

	sourceTestIntMessage->Load(messageSource);

	MESSAGE_MANAGER_SINGLETON.Remove(sm_FullMessageID);
}

void Network::IntegerDoubleMessageTesting
	::MessageTest()
{
	TestingType::IntegerType integerType{ 100,10,1000,2,100 };

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_FullMessageID,integerType) };

	ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
	ASSERT_EQUAL(testMessage->GetSubMessageID(), sm_SubMessageID);
	ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_FullMessageID);
}