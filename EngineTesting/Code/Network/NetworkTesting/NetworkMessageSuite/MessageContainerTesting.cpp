// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/12 13:55)

#include "MessageContainerTesting.h"  
#include "Flags/IntegerMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Network/NetworkMessage/MessageContainerDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h" 
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageContainerTesting)

namespace Network
{
	using TestingType = MessageContainer<IntegerMessageField, int64_t>;
	using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::MessageContainerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MessageContainerTesting
	::BaseTest()
{
	TestingType::MessageType message{ 100,10,10000,5,100 };
	TestingType messageContainer{ message };

	ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), boost::numeric_cast<int>(message.size()), "数组大小不相等！");

	for (auto i = 0; i < messageContainer.GetSize(); ++i)
	{
		ASSERT_EQUAL(message[i], messageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
	}
}

void Network::MessageContainerTesting
	::StreamingTest()
{
	TestingType::MessageType message{ 100,10,1000,2,100 };
	TestingType messageContainer{ message };

	ASSERT_EQUAL(messageContainer.GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(message));

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	messageContainer.Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	TestingType resultMessageContainer{ };

	resultMessageContainer.Load(messageSource);

	ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), resultMessageContainer.GetSize(), "数组大小不相等！");

	for (auto i = 0; i < messageContainer.GetSize(); ++i)
	{
		ASSERT_EQUAL(resultMessageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)), messageContainer.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
	}
}