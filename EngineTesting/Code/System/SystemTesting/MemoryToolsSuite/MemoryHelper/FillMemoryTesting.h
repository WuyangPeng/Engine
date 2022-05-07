///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/23 15:55)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_FILL_MEMORY_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_FILL_MEMORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FillMemoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FillMemoryTesting;
        using ParentType = UnitTest;

    public:
        explicit FillMemoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FillMemoryTest();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_FILL_MEMORY_TESTING_H