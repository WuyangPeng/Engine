///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:23)

#ifndef SYSTEM_THREADING_SUITE_EVENT_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_EVENT_TESTING_BASE_H

#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EventTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = EventTestingBase;
        using ParentType = UnitTest;

    public:
        explicit EventTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto threadCount = 12;

    protected:
        void CloseSystemEventTest(WindowsHandle eventHandle);
       
    };
}

#endif  // SYSTEM_THREADING_SUITE_EVENT_TESTING_BASE_H