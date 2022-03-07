// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:39)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_INT_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_INT_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestIntMessage : public MessageInterface
    {
    public:
        using ClassType = TestIntMessage;
        using ParentType = MessageInterface;

    public:
        explicit TestIntMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        int GetIntValue() const noexcept;

        void SetIntValue(int intValue) noexcept;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestIntMessage);

    private:
        int m_IntValue;
    };

    using TestIntMessageSharedPtr = std::shared_ptr<TestIntMessage>;
    using ConstTestIntMessageSharedPtr = std::shared_ptr<const TestIntMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_INT_MESSAGE_H
