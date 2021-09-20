// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:53)

#include "NullMessageTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h" 
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, NullMessage)

namespace Network
{
	using TestingTypeSharedPtr = shared_ptr<TestingType>;
}

void Network::NullMessageTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::NullMessageTesting
	::RttiTest()
{
	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID) };
	NullDoubleMessageSharedPtr nullDoubleMessage{ make_shared<NullDoubleMessage>(sm_MessageID) };

	ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
        ASSERT_TRUE(testMessage->IsDerived(TestingType::GetCurrentRttiType()));
        ASSERT_FALSE(testMessage->IsDerived(NullDoubleMessage::GetCurrentRttiType()));

	ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
	ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

	ASSERT_FALSE(testMessage->IsExactlyTypeOf(nullDoubleMessage));
	ASSERT_FALSE(testMessage->IsDerivedTypeOf(nullDoubleMessage));

	const auto& attiType = testMessage->GetRttiType();

	ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.NullMessage" });
}

void Network::NullMessageTesting
	::FactoryTest()
{
	constexpr auto intValue = 5;

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID) };

	MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition{}, TestingType::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_MessageID);

// 	auto factoryCreateMessage = TestingType::Factory(messageSource, sm_MessageID);
// 	auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestingType>(factoryCreateMessage);
// 
// 	ASSERT_UNEQUAL_NULL_PTR(polymorphicMessage);
// 
// 	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::NullMessageTesting
	::StreamingTest()
{
	constexpr auto intValue = 5;

	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID) };

	ASSERT_EQUAL(testMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_MessageID));

	MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition{}, TestingType::Factory);

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	testMessage->Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	int64_t sourceMessageID{ 0 };
	messageSource->Read(sourceMessageID);

	ASSERT_EQUAL(sourceMessageID, sm_MessageID);

	auto sourceTestIntMessage{ make_shared<TestingType>(sm_MessageID) };

	sourceTestIntMessage->Load(messageSource);

	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::NullMessageTesting
	::MessageTest()
{
	TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID) };

	ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
	ASSERT_EQUAL(testMessage->GetSubMessageID(), 0);
	ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_MessageID);
}

