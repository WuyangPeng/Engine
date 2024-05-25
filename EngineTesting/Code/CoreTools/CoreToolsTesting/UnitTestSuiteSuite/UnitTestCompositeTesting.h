/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:23)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_UNIT_TEST_COMPOSITE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_UNIT_TEST_COMPOSITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestCompositeTesting final : public UnitTest
    {
    public:
        using ClassType = UnitTestCompositeTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestCompositeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void UnitTestCompositeTest();
        void AddUnitTestExceptionTest();
        void ClearUnitTestCollectionTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_UNIT_TEST_COMPOSITE_TESTING_H