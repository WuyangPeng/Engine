///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 11:07)

#ifndef SYSTEM_THREADING_SUITE_CRITICAL_SECTION_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CRITICAL_SECTION_THREAD_TESTING_H

#include "System/Threading/Using/CriticalSectionUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CriticalSectionThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CriticalSectionThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit CriticalSectionThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();

        void Init();
        void Delete() noexcept;

        void EnterCriticalSectionTest() noexcept;
        void TryEnterCriticalSectionSucceedTest();
        void TryEnterCriticalSectionFailureTest();

    private:
        ThreadingCriticalSection criticalSection;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CRITICAL_SECTION_THREAD_TESTING_H