///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:19)

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
