///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/21 22:53)

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
        void DoRunUnitTest() final;
        void MainTest();

        void CreateHeapSucceedTest();
        void DoCreateHeapSucceedTest(HeapCreate flag);
        void CreateDefaultHeapSucceedTest(HeapCreate flag);

        void CreateHeapFailureTest();
        void DoCreateHeapFailureTest(HeapCreate flag);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_HEAP_TESTING_H