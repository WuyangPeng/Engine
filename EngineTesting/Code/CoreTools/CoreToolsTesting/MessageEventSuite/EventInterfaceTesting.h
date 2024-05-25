/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:00)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H

#include "Detail/EventSubclass.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventInterfaceTesting final : public UnitTest
    {
    public:
        using ClassType = EventInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit EventInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto value = 5;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EventSubclassTest();
        void EventFunctionTest(EventSubclass& eventSubclass);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H