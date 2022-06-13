///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 16:51)

#include "MessageInterfaceSharedPtrLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageInterfaceSharedPtrLess.h"
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/NullMessage.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageInterfaceSharedPtrLess)

void Network::MessageInterfaceSharedPtrLessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleMessageTest);
}

void Network::MessageInterfaceSharedPtrLessTesting::LessTest()
{
    NullMessageSharedPtr lhsTestMessage{ make_shared<NullMessage>(5) };
    NullMessageSharedPtr rhsTestMessage{ make_shared<NullMessage>(6) };

    TestingType less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}

void Network::MessageInterfaceSharedPtrLessTesting::DoubleMessageTest()
{
    constexpr int64_t messageBytes{ 32LL };
    NullDoubleMessageSharedPtr lhsTestMessage{ make_shared<NullDoubleMessage>((int64_t{ 6 } << messageBytes) + int64_t{ 5 }) };
    NullDoubleMessageSharedPtr rhsTestMessage{ make_shared<NullDoubleMessage>((int64_t{ 6 } << messageBytes) + int64_t{ 6 }) };

    TestingType less{};

    ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}
