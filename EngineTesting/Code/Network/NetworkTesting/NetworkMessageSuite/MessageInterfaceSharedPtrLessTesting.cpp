// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:57)

#include "MessageInterfaceSharedPtrLessTesting.h"  
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/MessageInterfaceSharedPtrLess.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageInterfaceSharedPtrLess)

void Network::MessageInterfaceSharedPtrLessTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DoubleMessageTest);
}

void Network::MessageInterfaceSharedPtrLessTesting
	::LessTest()
{
	NullMessageSharedPtr lhsTestMessage{ make_shared<NullMessage>(5) };
	NullMessageSharedPtr rhsTestMessage{ make_shared<NullMessage>(6) };

	TestingType less{};

	ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}

void Network::MessageInterfaceSharedPtrLessTesting
	::DoubleMessageTest()
{
	constexpr int64_t messageBytes{ 32LL };
	NullDoubleMessageSharedPtr lhsTestMessage{ make_shared<NullDoubleMessage>((int64_t{ 6 } << messageBytes) + int64_t{ 5 }) };
	NullDoubleMessageSharedPtr rhsTestMessage{ make_shared<NullDoubleMessage>((int64_t{ 6 } << messageBytes) + int64_t{ 6 }) };

	TestingType less{};

	ASSERT_TRUE(less(lhsTestMessage, rhsTestMessage));
}

