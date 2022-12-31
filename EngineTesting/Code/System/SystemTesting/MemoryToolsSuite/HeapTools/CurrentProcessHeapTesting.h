///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/21 23:08)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H

#include "HeapTestingBase.h"

#include <array>

namespace System
{
    class CurrentProcessHeapTesting final : public HeapTestingBase
    {
    public:
        using ClassType = CurrentProcessHeapTesting;
        using ParentType = HeapTestingBase;

    public:
        explicit CurrentProcessHeapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto bufferSize = 256u;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CurrentProcessHeapTest();
        void CurrentProcessHeapsTest();
        void AfterCreateHeapTest(WindowsHandle defaultHandle, WindowsHandle newHandle);
        void DefaultHeapTest(WindowsHandle defaultHandle);

    private:
        using HeapsType = std::array<WindowsHandle, bufferSize>;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H