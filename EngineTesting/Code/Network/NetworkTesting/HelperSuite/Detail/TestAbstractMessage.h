///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 09:38)

#ifndef NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H
#define NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H

#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class TestAbstractMessage : public MessageInterface
    {
    public:
        using ClassType = TestAbstractMessage;
        using ParentType = MessageInterface;

    public:
        TestAbstractMessage() noexcept;
        virtual ~TestAbstractMessage() noexcept = 0;
        TestAbstractMessage(const TestAbstractMessage& rhs) noexcept = default;
        TestAbstractMessage& operator=(const TestAbstractMessage& rhs) noexcept = default;
        TestAbstractMessage(TestAbstractMessage&& rhs) noexcept = default;
        TestAbstractMessage& operator=(TestAbstractMessage&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestAbstractMessage);
    };

}

#endif  // NETWORK_TESTING_HELPER_SUITE_TEST_ABSTRACT_MESSAGE_H