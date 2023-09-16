///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:32)

#ifndef SYSTEM_THREADING_SUITE_MUTEX_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_MUTEX_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MutexTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = MutexTestingBase;
        using ParentType = UnitTest;

    public:
        explicit MutexTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto threadCount = 12;

    protected:
        void CloseMutexTest(WindowsHandle mutexHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_MUTEX_TESTING_BASE_H