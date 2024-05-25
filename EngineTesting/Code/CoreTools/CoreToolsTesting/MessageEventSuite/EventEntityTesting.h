/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:00)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H

#include "Detail/Entity.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void EventTest();

        void DoEventTest(Entity& entity, const CallbackParameters& callbackParameters);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H