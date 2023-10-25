///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 15:28)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventEntityTesting final : public UnitTest
    {
    public:
        using ClassType = EventEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit EventEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void EventTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H