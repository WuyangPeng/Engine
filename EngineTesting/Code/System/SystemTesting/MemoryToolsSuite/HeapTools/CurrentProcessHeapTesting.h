///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/20 15:49)

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