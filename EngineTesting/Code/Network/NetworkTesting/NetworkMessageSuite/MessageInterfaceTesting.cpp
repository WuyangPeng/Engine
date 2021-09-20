// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:58)

#include "MessageInterfaceTesting.h" 
#include "Detail/TestNullMessage.h"
#include "Detail/TestIntMessage.h"
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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageInterfaceTesting)

void Network::MessageInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::MessageInterfaceTesting
	::RttiTest()
{
	TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(sm_MessageID) };
	TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

	ASSERT_TRUE(testMessage->IsExactly(TestNullMessage::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
        ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

	ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
	ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

	ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
	ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

	const auto& attiType = testMessage->GetRttiType();

	ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.TestNullMessage" });

	constexpr auto messsageHeadSize = 16;

	ASSERT_EQUAL(MessageInterface::GetMessageHeadSize(), messsageHeadSize);
}

void Network::MessageInterfaceTesting
	::FactoryTest()
{
	constexpr auto intValue = 5;

	TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

	testIntMessage->SetIntValue(intValue);

	MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition{}, TestIntMessage::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testIntMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_MessageID);

// 	auto factoryCreateMessage = TestIntMessage::Factory(messageSource, sm_MessageID);
// 	auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestIntMessage>(factoryCreateMessage);
// 
// 	ASSERT_EQUAL(polymorphicMessage->GetIntValue(), intValue);
// 
// 	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::MessageInterfaceTesting
	::StreamingTest()
{
	constexpr auto intValue = 5;

	TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

	ASSERT_EQUAL(testIntMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_MessageID) + CORE_TOOLS_STREAM_SIZE(intValue));

	testIntMessage->SetIntValue(intValue);

	MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition{}, TestIntMessage::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testIntMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_MessageID);

	auto sourceTestIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

	sourceTestIntMessage->Load(messageSource);

	ASSERT_EQUAL(sourceTestIntMessage->GetIntValue(), intValue);

	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::MessageInterfaceTesting
	::MessageTest()
{
	TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(sm_MessageID) };

	ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
	ASSERT_EQUAL(testMessage->GetSubMessageID(), 0);
	ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_MessageID);
}