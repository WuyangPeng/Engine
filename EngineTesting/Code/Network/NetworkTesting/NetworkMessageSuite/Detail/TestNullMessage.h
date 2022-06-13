///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:19)

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
        explicit TestNullMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetValue() const;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestNullMessage);
    };

    using TestNullMessageSharedPtr = std::shared_ptr<TestNullMessage>;
    using ConstTestNullMessageSharedPtr = std::shared_ptr<const TestNullMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_NULL_MESSAGE_H
