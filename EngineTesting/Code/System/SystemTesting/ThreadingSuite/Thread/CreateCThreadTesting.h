///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:38)

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
        void DoRunUnitTest() override;
        void MainTest();

        void BeginThreadExTest();

        static unsigned int SYSTEM_WINAPI ThreadStartRoutineEx(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_C_THREAD_TESTING_H