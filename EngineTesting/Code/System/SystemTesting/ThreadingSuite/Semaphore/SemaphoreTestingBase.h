///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 14:54)

#ifndef SYSTEM_THREADING_SUITE_SEMAPHORE_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_SEMAPHORE_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SemaphoreTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SemaphoreTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SemaphoreTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto threadCount = 12;

    protected:
        void CloseSemaphoreTest(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SEMAPHORE_TESTING_BASE_H