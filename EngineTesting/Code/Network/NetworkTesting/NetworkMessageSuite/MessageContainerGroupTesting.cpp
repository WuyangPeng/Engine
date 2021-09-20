// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/12 13:52)

#include "MessageContainerGroupTesting.h"  
#include "Flags/IntegerMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h" 
#include "Network/NetworkMessage/MessageContainerGroupDetail.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageContainerGroupTesting)

namespace Network
{
	using TestingType = MessageContainerGroup<IntegerMessageField, int64_t>;
	using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::MessageContainerGroupTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MessageContainerGroupTesting
	::BaseTest()
{
	TestingType::StructureType group{ { 100,10,10000,5,100 } , { 101,11,10001,6,101 } , { 102,12,10002,7,102 } , { 103,13,10003,8,103 } };
	TestingType messageContainer{ group };

	ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), boost::numeric_cast<int>(group.size()), "数组大小不相等！");

	auto index = 0;
	for (const auto& value : messageContainer)
	{
		for (auto i = 0; i < value.GetSize(); ++i)
		{
			ASSERT_EQUAL(group[index][i], value.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
		}

		++index;
	}
}

void Network::MessageContainerGroupTesting
	::StreamingTest()
{
	TestingType::StructureType group{ { 100,10,10000,5,100 } , { 101,11,10001,6,101 } , { 102,12,10002,7,102 } , { 103,13,10003,8,103 } };
	TestingType messageContainer{ group };

	ASSERT_EQUAL(messageContainer.GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(group[0]) * boost::numeric_cast<int>(group.size()) + CORE_TOOLS_STREAM_SIZE(int32_t{}));

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	messageContainer.Save(messageTarget);

	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

	TestingType resultMessageContainer{ };

	resultMessageContainer.Load(messageSource);

	ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), resultMessageContainer.GetSize(), "数组大小不相等！");

	auto index = 0;
	for (const auto& resultValue : resultMessageContainer)
	{
		const auto& value = messageContainer.GetValue(index);

		ASSERT_EQUAL_FAILURE_THROW(value.GetSize(), resultValue.GetSize(), "数组大小不相等！");

		for (auto i = 0; i < resultValue.GetSize(); ++i)
		{
			ASSERT_EQUAL(value.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)), resultValue.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
		}

		++index;
	}
}