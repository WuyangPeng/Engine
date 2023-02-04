///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 9:28)

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