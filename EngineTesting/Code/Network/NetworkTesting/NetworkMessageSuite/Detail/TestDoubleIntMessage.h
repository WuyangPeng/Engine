///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:15)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H

#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestDoubleIntMessage : public MessageInterface
    {
    public:
        using ClassType = TestDoubleIntMessage;
        using ParentType = MessageInterface;

    public:
        explicit TestDoubleIntMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetIntValue() const noexcept;

        void SetIntValue(int intValue) noexcept;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestDoubleIntMessage);

    private:
        int mIntValue;
    };

    using TestDoubleIntMessageSharedPtr = std::shared_ptr<TestDoubleIntMessage>;
    using ConstTestDoubleIntMessageSharedPtr = std::shared_ptr<const TestDoubleIntMessage>;
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_TEST_DOUBLE_INT_MESSAGE_H
