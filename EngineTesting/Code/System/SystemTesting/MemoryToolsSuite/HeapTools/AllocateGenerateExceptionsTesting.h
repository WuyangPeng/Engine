///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/19 21:09)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H

#include "HeapTestingBase.h"

namespace System
{
    class AllocateGenerateExceptionsTesting final : public HeapTestingBase
    {
    public:
        using ClassType = AllocateGenerateExceptionsTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit AllocateGenerateExceptionsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AllocateGenerateExceptionsHeapSucceedTest();
        void AllocateGenerateExceptionsHeapSucceedLoop(WindowsHandle handle);
        void DoAllocateGenerateExceptionsHeapSucceedTest(WindowsHandle handle, HeapCreate flag);
        void GetProcessHeapSizeSucceedTest(WindowsHandle handle, HeapCreate flag, WindowsVoidPtr memory);

        void AllocateGenerateExceptionsHeapFailureTest();
        void AllocateGenerateExceptionsHeapFailuredLoop(WindowsHandle handle);
        void DoAllocateGenerateExceptionsHeapFailureTest(WindowsHandle handle, HeapCreate flag);

    private:
        WindowsSize size;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H