///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:25)

#ifndef SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_AND_SPIN_COUNT_TESTING_H
#define SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_AND_SPIN_COUNT_TESTING_H

#include "System/Threading/Using/CriticalSectionUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SpecifyCriticalSectionAndSpinCountTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SpecifyCriticalSectionAndSpinCountTesting;
        using ParentType = UnitTest;

    public:
        explicit SpecifyCriticalSectionAndSpinCountTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CriticalSectionTest();

        void EnterCriticalSectionTest(ThreadingCriticalSection& criticalSection);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_AND_SPIN_COUNT_TESTING_H