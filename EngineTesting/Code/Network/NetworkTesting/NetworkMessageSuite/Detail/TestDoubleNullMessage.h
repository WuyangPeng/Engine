// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:39)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H

#include "Network/NetworkMessage/DoubleMessage.h" 

namespace Network
{
	class TestDoubleNullMessage : public DoubleMessage
	{
	public:
		using ClassType = TestDoubleNullMessage;
		using ParentType = DoubleMessage;

	public:
		explicit TestDoubleNullMessage(int64_t messageID);
		virtual ~TestDoubleNullMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetValue() const;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(TestDoubleNullMessage);
	};

	using TestDoubleNullMessageSharedPtr = std::shared_ptr<TestDoubleNullMessage>;
	using ConstTestDoubleNullMessageSharedPtr = std::shared_ptr<const TestDoubleNullMessage>;
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H
