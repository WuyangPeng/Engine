///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 16:20)

#include "MessageContainerGroupTesting.h"
#include "Flags/IntegerMessageType.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageContainerGroupDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageContainerGroupTesting)

namespace Network
{
    using TestingType = MessageContainerGroup<IntegerMessageField, int64_t>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::MessageContainerGroupTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MessageContainerGroupTesting::BaseTest()
{
    TestingType::StructureType group{ { 100, 10, 10000, 5, 100 }, { 101, 11, 10001, 6, 101 }, { 102, 12, 10002, 7, 102 }, { 103, 13, 10003, 8, 103 } };
    TestingType messageContainer{ group };

    ASSERT_EQUAL_FAILURE_THROW(messageContainer.GetSize(), boost::numeric_cast<int>(group.size()), "数组大小不相等！");

    auto index = 0;
    for (const auto& value : messageContainer)
    {
        for (auto i = 0; i < value.GetSize(); ++i)
        {
            ASSERT_EQUAL(group.at(index).at(i), value.GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
        }

        ++index;
    }
}

void Network::MessageContainerGroupTesting::StreamingTest()
{
    TestingType::StructureType group{ { 100, 10, 10000, 5, 100 }, { 101, 11, 10001, 6, 101 }, { 102, 12, 10002, 7, 102 }, { 103, 13, 10003, 8, 103 } };
    TestingType messageContainer{ group };

    ASSERT_EQUAL(messageContainer.GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(group.at(0)) * boost::numeric_cast<int>(group.size()) + CORE_TOOLS_STREAM_SIZE(int32_t{}));

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto buffer = make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian);
    auto messageTarget = make_shared<MessageTarget>(buffer);

    messageContainer.Save(*messageTarget);

    auto messageSource = make_shared<MessageSource>(buffer);

#include STSTEM_WARNING_POP

    TestingType resultMessageContainer{};

    resultMessageContainer.Load(*messageSource);

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