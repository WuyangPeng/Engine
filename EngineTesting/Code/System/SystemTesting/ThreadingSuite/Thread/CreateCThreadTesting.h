///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:37)

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