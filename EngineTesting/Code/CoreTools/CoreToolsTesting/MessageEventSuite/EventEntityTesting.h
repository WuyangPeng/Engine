///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:17)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class EventEntityTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EventEntityTesting);

    private:
        void MainTest();

        void EventTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_ENTITY_TESTING_H