/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:12)

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