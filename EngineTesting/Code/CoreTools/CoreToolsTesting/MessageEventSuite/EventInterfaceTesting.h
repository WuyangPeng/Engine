///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:18)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventInterfaceTesting : public UnitTest
    {
    public:
        using ClassType = EventInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit EventInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;


    private:
        void MainTest();
        void EventSubclassTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H