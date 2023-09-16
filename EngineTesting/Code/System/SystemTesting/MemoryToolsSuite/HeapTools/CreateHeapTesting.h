///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:59)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H

#include "HeapTestingBase.h"

namespace System
{
    class CreateHeapTesting final : public HeapTestingBase
    {
    public:
        using ClassType = CreateHeapTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit CreateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateHeapSucceedTest();
        void DoCreateHeapSucceedTest(HeapCreate flag);
        void CreateDefaultHeapSucceedTest(HeapCreate flag);

        void CreateHeapFailureTest();
        void DoCreateHeapFailureTest(HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H