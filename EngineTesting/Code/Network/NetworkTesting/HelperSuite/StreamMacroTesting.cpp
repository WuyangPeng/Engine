// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:03)

#include "StreamMacroTesting.h"
#include "Detail/TestMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Network/NetworkMessage/MessageTarget.h"
#include "Network/NetworkMessage/MessageSource.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <boost/numeric/conversion/cast.hpp>
#include <array>

using std::array;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, StreamMacroTesting)

void Network::StreamMacroTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TestMessageTest);
}

void Network::StreamMacroTesting
	::TestMessageTest()
{
// 	constexpr auto size = 256;
// 	TestMessageSmartPointer testMessage{ NEW0 TestMessage };
// 
// 	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024,0,ParserStrategy::LittleEndian) };
// 
// 	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };
// 
// 	MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };
// 
// 	testMessage->Load(messageSource);
// 	testMessage->Save(messageTarget);
// 
// 	ASSERT_LESS(0, testMessage->GetStreamingSize());
}

