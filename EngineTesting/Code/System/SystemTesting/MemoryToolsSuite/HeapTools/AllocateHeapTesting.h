///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/21 22:15)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H

#include "HeapTestingBase.h"

namespace System
{
    class AllocateHeapTesting final : public HeapTestingBase
    {
    public:
        using ClassType = AllocateHeapTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit AllocateHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AllocateDefaultHeapSucceedTest();
        void AllocateDefaultHeapSucceedLoop(WindowsHandle handle);
        void DoAllocateDefaultHeapSucceedTest(WindowsHandle handle, HeapCreate flag);
        void GetProcessHeapSizeSucceedTest(WindowsHandle handle, HeapCreate flag, WindowsVoidPtr memory);

        void AllocateDefaultHeapFailureTest();
        void AllocateDefaultHeapFailureLoop(WindowsHandle handle);
        void DoAllocateDefaultHeapFailureTest(WindowsHandle handle, HeapCreate flag);

        void AllocateIntegerTest();

    private:
        WindowsSize size;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_HEAP_TESTING_H