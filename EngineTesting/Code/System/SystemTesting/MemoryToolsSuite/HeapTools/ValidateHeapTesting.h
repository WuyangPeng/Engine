///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:00)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VALIDATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VALIDATE_HEAP_TESTING_H

#include "HeapTestingBase.h"

namespace System
{
    class ValidateHeapTesting final : public HeapTestingBase
    {
    public:
        using ClassType = ValidateHeapTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit ValidateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ValidateHeapTest();
        void ValidateTest(HeapCreate flag);
        void DoValidateTest(WindowsHandle handle, HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H