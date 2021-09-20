///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/23 15:55)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MemorySetTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemorySetTesting;
        using ParentType = UnitTest;

    public:
        explicit MemorySetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MemorySetTest();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_MEMORY_SET_TESTING_H