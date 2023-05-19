///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 11:34)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestNullMessage final : public MessageInterface
    {
    public:
        using ClassType = TestNullMessage;
        using ParentType = MessageInterface;

    public:
        explicit TestNullMessage(int64_t messageId) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetValue() const;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestNullMessage);
    };

    using TestNullMessageSharedPtr = std::shared_ptr<TestNullMessage>;
    using ConstTestNullMessageSharedPtr = std::shared_ptr<const TestNullMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H
