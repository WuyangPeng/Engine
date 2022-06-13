///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:10)

#ifndef SYSTEM_THREADING_SUITE_CRITICAL_SECTION_TESTING_H
#define SYSTEM_THREADING_SUITE_CRITICAL_SECTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CriticalSectionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CriticalSectionTesting;
        using ParentType = UnitTest;

    public:
        explicit CriticalSectionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CriticalSectionTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CRITICAL_SECTION_TESTING_H