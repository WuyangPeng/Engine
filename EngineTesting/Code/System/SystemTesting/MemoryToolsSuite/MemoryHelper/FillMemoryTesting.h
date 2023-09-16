///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:01)

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
        void DoRunUnitTest() override;
        void MainTest();

        void FillMemoryTest();
        void FillConsoleFontInfoTest();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_FILL_MEMORY_TESTING_H