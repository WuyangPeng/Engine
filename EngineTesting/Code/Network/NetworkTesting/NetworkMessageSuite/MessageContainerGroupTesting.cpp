///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:45)

#include "MessageContainerGroupTesting.h"
#include "Flags/IntegerMessageType.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageContainerGroupDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::MessageContainerGroupTesting::MessageContainerGroupTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageContainerGroupTesting)

void Network::MessageContainerGroupTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
    const TestingType::StructureType group{ { 100, 10, 10000, 5, 100 }, { 101, 11, 10001, 6, 101 }, { 102, 12, 10002, 7, 102 }, { 103, 13, 10003, 8, 103 } };
    const TestingType messageContainer{ group };

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
    const TestingType::StructureType group{ { 100, 10, 10000, 5, 100 }, { 101, 11, 10001, 6, 101 }, { 102, 12, 10002, 7, 102 }, { 103, 13, 10003, 8, 103 } };
    const TestingType messageContainer{ group };

    ASSERT_EQUAL(messageContainer.GetStreamingSize(), CoreTools::GetStreamSize(group.at(0)) * boost::numeric_cast<int>(group.size()) + CoreTools::GetStreamSize(int32_t{}));

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    messageContainer.Save(messageTarget);

    MessageSource messageSource{ buffer };

    TestingType resultMessageContainer{};

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