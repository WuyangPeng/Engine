///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:58)

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
        void DoRunUnitTest() override;
        void MainTest();

        void AllocateGenerateExceptionsHeapSucceedTest();
        void AllocateGenerateExceptionsHeapSucceedLoop(WindowsHandle handle);
        void DoAllocateGenerateExceptionsHeapSucceedTest(WindowsHandle handle, HeapCreate flag);
        void GetProcessHeapSizeSucceedTest(WindowsHandle handle, HeapCreate flag, WindowsVoidPtr memory);

        void AllocateGenerateExceptionsHeapFailureTest();
        void AllocateGenerateExceptionsHeapFailureLoop(WindowsHandle handle);
        void DoAllocateGenerateExceptionsHeapFailureTest(WindowsHandle handle, HeapCreate flag);

    private:
        WindowsSize size;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ALLOCATE_GENERATE_EXCEPTIONS_TESTING_H