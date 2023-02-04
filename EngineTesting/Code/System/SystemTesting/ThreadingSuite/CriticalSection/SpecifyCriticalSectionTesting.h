///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 23:28)

#ifndef SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_TESTING_H
#define SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_TESTING_H

#include "System/Threading/Using/CriticalSectionUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SpecifyCriticalSectionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SpecifyCriticalSectionTesting;
        using ParentType = UnitTest;

    public:
        explicit SpecifyCriticalSectionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SpecifyCriticalSectionTest();

        void EnterCriticalSectionTest(ThreadingCriticalSection& criticalSection);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SPECIFY_CRITICAL_SECTION_TESTING_H