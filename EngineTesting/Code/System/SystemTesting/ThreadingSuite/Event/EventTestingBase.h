/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 17:58)

#ifndef SYSTEM_THREADING_SUITE_EVENT_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_EVENT_TESTING_BASE_H

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