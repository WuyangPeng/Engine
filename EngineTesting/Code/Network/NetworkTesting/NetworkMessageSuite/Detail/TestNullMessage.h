// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:40)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h" 

namespace Network
{
	class TestNullMessage : public MessageInterface
	{
	public:
		using ClassType = TestNullMessage;
		using ParentType = MessageInterface;

	public:
		explicit TestNullMessage(int64_t messageID);
		virtual ~TestNullMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetValue() const;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(TestNullMessage);
	};

	using TestNullMessageSharedPtr = std::shared_ptr<TestNullMessage>;
	using ConstTestNullMessageSharedPtr = std::shared_ptr<const TestNullMessage>;
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H
