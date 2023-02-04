///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 19:42)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TOOLS_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_THREAD_TOOLS_TESTING_BASE_H

#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadToolsTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadToolsTestingBase;
        using ParentType = UnitTest;

    public:
        explicit ThreadToolsTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto exitFunctionCode = 1u;

    protected:
        void CloseMutexTest(WindowsHandle mutexHandle);
        void CloseThreadTest(ThreadHandle threadHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TOOLS_TESTING_BASE_H