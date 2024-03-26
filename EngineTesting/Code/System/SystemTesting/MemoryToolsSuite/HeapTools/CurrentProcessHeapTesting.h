/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 22:23)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CurrentProcessHeapTest();
        void CurrentProcessHeapsTest();
        void AfterCreateHeapTest(WindowsHandle defaultHandle, WindowsHandle newHandle);
        void DefaultHeapTest(WindowsHandle defaultHandle);

    private:
        using HeapsType = std::array<WindowsHandle, defaultBufferSize>;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H