///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 16:51)

#include "MessageInterfaceSharedPtrLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/MessageInterfaceSharedPtrLess.h"
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/NullMessage.h"
using std::make_shared;

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
    NullMessageSharedPtr lhsTestMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, 5) };
    NullMessageSharedPtr rhsTestMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, 6) };

    MessageInterfaceSharedPtrLess less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}

void Network::MessageInterfaceSharedPtrLessTesting::DoubleMessageTest()
{
    constexpr int64_t messageBytes{ 32LL };
    NullDoubleMessageSharedPtr lhsTestMessage{ make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, (int64_t{ 6 } << messageBytes) + int64_t{ 5 }) };
    NullDoubleMessageSharedPtr rhsTestMessage{ make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, (int64_t{ 6 } << messageBytes) + int64_t{ 6 }) };

    MessageInterfaceSharedPtrLess less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}
