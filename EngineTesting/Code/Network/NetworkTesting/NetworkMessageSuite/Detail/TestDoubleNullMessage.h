///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 11:33)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestDoubleNullMessage : public MessageInterface
    {
    public:
        using ClassType = TestDoubleNullMessage;
        using ParentType = MessageInterface;

    public:
        explicit TestDoubleNullMessage(int64_t messageId) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetValue() const;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestDoubleNullMessage);
    };

    using TestDoubleNullMessageSharedPtr = std::shared_ptr<TestDoubleNullMessage>;
    using ConstTestDoubleNullMessageSharedPtr = std::shared_ptr<const TestDoubleNullMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H
