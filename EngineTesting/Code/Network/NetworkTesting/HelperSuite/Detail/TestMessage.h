// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:01)

#ifndef NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H
#define NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H

#include "TestAbstractMessage.h"  

namespace Network
{
	class TestMessage : public TestAbstractMessage
	{
	public:
		using ClassType = TestMessage;
		using ParentType = TestAbstractMessage;

	public:
		TestMessage() noexcept; 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
		NETWORK_STREAM_DECLARE(TestMessage);
	};

	 
}

#endif // NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H