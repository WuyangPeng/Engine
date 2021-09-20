// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:27)

#include "DoubleMessageTesting.h" 
#include "Detail/TestDoubleNullMessage.h"
#include "Detail/TestDoubleIntMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, DoubleMessageTesting)

void Network::DoubleMessageTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::DoubleMessageTesting
	::RttiTest()
{
	TestDoubleNullMessageSharedPtr testMessage{ make_shared<TestDoubleNullMessage>(sm_FullMessageID) };
	TestDoubleIntMessageSharedPtr testIntMessage{ make_shared<TestDoubleIntMessage>(sm_FullMessageID) };

	ASSERT_TRUE(testMessage->IsExactly(TestDoubleNullMessage::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsExactly(DoubleMessage::GetCurrentRttiType()));
        ASSERT_TRUE(testMessage->IsDerived(DoubleMessage::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsDerived(TestDoubleIntMessage::GetCurrentRttiType()));

	ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
	ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

	ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
	ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

	const auto& attiType = testMessage->GetRttiType();

	ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.TestDoubleNullMessage" });
}

void Network::DoubleMessageTesting
	::FactoryTest()
{
	constexpr auto intValue = 5;

	TestDoubleIntMessageSharedPtr testIntMessage{ make_shared<TestDoubleIntMessage>(sm_FullMessageID) };

	testIntMessage->SetIntValue(intValue);

	MESSAGE_MANAGER_SINGLETON.Insert(sm_FullMessageID, MessageTypeCondition{}, TestDoubleIntMessage::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testIntMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_FullMessageID);

	auto factoryCreateMessage = TestDoubleIntMessage::Factory(messageSource, sm_FullMessageID);
//	auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestDoubleIntMessage>(factoryCreateMessage);

//	ASSERT_EQUAL(polymorphicMessage->GetIntValue(), intValue);

	MESSAGE_MANAGER_SINGLETON.Remove(sm_FullMessageID);
}

void Network::DoubleMessageTesting
	::StreamingTest()
{
	constexpr auto intValue = 5;

	TestDoubleIntMessageSharedPtr testIntMessage{ make_shared<TestDoubleIntMessage>(sm_FullMessageID) };

	ASSERT_EQUAL(testIntMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_FullMessageID) + CORE_TOOLS_STREAM_SIZE(intValue));

	testIntMessage->SetIntValue(intValue);

	MESSAGE_MANAGER_SINGLETON.Insert(sm_FullMessageID, MessageTypeCondition{}, TestDoubleIntMessage::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testIntMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_FullMessageID);

	auto sourceTestIntMessage{ make_shared<TestDoubleIntMessage>(sm_FullMessageID) };

	sourceTestIntMessage->Load(messageSource);

	ASSERT_EQUAL(sourceTestIntMessage->GetIntValue(), intValue);

	MESSAGE_MANAGER_SINGLETON.Remove(sm_FullMessageID);
}

void Network::DoubleMessageTesting
	::MessageTest()
{
	TestDoubleNullMessageSharedPtr testMessage{ make_shared<TestDoubleNullMessage>(sm_FullMessageID) };

	ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
	ASSERT_EQUAL(testMessage->GetSubMessageID(), sm_SubMessageID);
	ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_FullMessageID);
}