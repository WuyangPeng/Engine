///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:49)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VALIDATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VALIDATE_HEAP_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ValidateHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ValidateHeapTesting;
        using ParentType = UnitTest;

    public:
        explicit ValidateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ValidateTest(HeapCreate flag);
        void DoValidateTest(WindowsHandle handle, HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H