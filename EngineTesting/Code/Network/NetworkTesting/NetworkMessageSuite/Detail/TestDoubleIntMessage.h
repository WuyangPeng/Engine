// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:38)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H

#include "Network/NetworkMessage/DoubleMessage.h"

namespace Network
{
    class TestDoubleIntMessage : public DoubleMessage
    {
    public:
        using ClassType = TestDoubleIntMessage;
        using ParentType = DoubleMessage;

    public:
        explicit TestDoubleIntMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        int GetIntValue() const noexcept;

        void SetIntValue(int intValue) noexcept;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestDoubleIntMessage);

    private:
        int m_IntValue;
    };

    using TestDoubleIntMessageSharedPtr = std::shared_ptr<TestDoubleIntMessage>;
    using ConstTestDoubleIntMessageSharedPtr = std::shared_ptr<const TestDoubleIntMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
