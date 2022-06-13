///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:17)

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

        NODISCARD int GetIntValue() const noexcept;

        void SetIntValue(int intValue) noexcept;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestIntMessage);

    private:
        int mIntValue;
    };

    using TestIntMessageSharedPtr = std::shared_ptr<TestIntMessage>;
    using ConstTestIntMessageSharedPtr = std::shared_ptr<const TestIntMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_INT_MESSAGE_H
