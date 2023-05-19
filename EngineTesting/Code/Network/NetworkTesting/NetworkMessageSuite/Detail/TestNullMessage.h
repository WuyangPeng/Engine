///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 11:34)

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
