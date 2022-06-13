///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:37)

#ifndef SYSTEM_THREADING_SUITE_CREATE_C_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_C_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateCThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateCThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateCThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool BeginThreadExTest();

        static unsigned SYSTEM_WINAPI ThreadStartRoutineEx(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_C_THREAD_TESTING_H