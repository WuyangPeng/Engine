///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:49)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CurrentProcessHeapTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CurrentProcessHeapTesting;
        using ParentType = UnitTest;

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
        void AfterCreateHeapTest(WindowsHandle processHandle);
        void DefaultHeapTest(WindowsHandle processHandle);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_ASSIST_HEAP_TESTING_H