// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:01)

#ifndef NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H
#define NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H

 
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageInterface.h" 

namespace Network
{
	class TestAbstractMessage : public MessageInterface
	{
	public:
		using ClassType = TestAbstractMessage;
		using ParentType = MessageInterface;

	public:
		TestAbstractMessage();
		virtual ~TestAbstractMessage() = 0;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(TestAbstractMessage);
	};

 
}

#endif // NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H