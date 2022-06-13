///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:16)

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
        explicit TestDoubleNullMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetValue() const;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestDoubleNullMessage);
    };

    using TestDoubleNullMessageSharedPtr = std::shared_ptr<TestDoubleNullMessage>;
    using ConstTestDoubleNullMessageSharedPtr = std::shared_ptr<const TestDoubleNullMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_NULL_MESSAGE_H
