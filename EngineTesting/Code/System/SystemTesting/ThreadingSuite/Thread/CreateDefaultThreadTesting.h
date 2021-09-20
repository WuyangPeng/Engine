///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 14:52)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateDefaultThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateDefaultThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateDefaultThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool ThreadTest();

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H