/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:52)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_IN_TOP_LEVEL_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_IN_TOP_LEVEL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InTopLevelTesting final : public UnitTest
    {
    public:
        using ClassType = InTopLevelTesting;
        using ParentType = UnitTest;

    public:
        explicit InTopLevelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BasisTest();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_IN_TOP_LEVEL_TESTING_H