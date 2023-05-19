///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 09:38)

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