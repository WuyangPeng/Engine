///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:01)

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

        void BeginThreadExTest();

        static unsigned int SYSTEM_WINAPI ThreadStartRoutineEx(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_C_THREAD_TESTING_H