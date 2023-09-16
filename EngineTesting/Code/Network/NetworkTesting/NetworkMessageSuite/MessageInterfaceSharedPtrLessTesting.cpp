///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:47)

#include "MessageInterfaceSharedPtrLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/MessageInterfaceSharedPtrLess.h"
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::MessageInterfaceSharedPtrLessTesting::MessageInterfaceSharedPtrLessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageInterfaceSharedPtrLessTesting)

void Network::MessageInterfaceSharedPtrLessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageInterfaceSharedPtrLessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleMessageTest);
}

void Network::MessageInterfaceSharedPtrLessTesting::LessTest()
{
    const auto lhsTestMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, 5);
    const auto rhsTestMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, 6);

    constexpr MessageInterfaceSharedPtrLess less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}

void Network::MessageInterfaceSharedPtrLessTesting::DoubleMessageTest()
{
    constexpr auto messageBytes = 32LL;
    const auto lhsTestMessage = std::make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, (6LL << messageBytes) + 5LL);
    const auto rhsTestMessage = std::make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, (6LL << messageBytes) + 6LL);

    constexpr MessageInterfaceSharedPtrLess less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}
