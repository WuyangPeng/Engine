///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 11:36)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H

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
        void MainTest();
        void EventSubclassTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_INTERFACE_TESTING_H