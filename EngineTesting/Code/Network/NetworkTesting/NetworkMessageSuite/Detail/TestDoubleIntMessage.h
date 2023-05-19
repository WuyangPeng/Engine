///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 11:33)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestDoubleIntMessage final : public MessageInterface
    {
    public:
        using ClassType = TestDoubleIntMessage;
        using ParentType = MessageInterface;

    public:
        explicit TestDoubleIntMessage(int64_t messageId) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetIntValue() const noexcept;

        void SetIntValue(int aIntValue) noexcept;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestDoubleIntMessage);

    private:
        int intValue;
    };

    using TestDoubleIntMessageSharedPtr = std::shared_ptr<TestDoubleIntMessage>;
    using ConstTestDoubleIntMessageSharedPtr = std::shared_ptr<const TestDoubleIntMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
