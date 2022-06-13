///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 15:28)

#ifndef NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H
#define NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H

#include "TestAbstractMessage.h"

namespace Network
{
    class TestMessage : public TestAbstractMessage
    {
    public:
        using ClassType = TestMessage;
        using ParentType = TestAbstractMessage;

    public:
        TestMessage() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(TestMessage);
    };
}

#endif  // NETWORK_TESTING_HELPER_SUITE_TEST_MESSAGE_H