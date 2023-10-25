///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 13:42)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_ARRAY2_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_ARRAY2_TESTING_H

#include "CoreTools/MemoryTools/Array2.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class Array2Testing final : public UnitTest
    {
    public:
        using ClassType = Array2Testing;
        using ParentType = UnitTest;

    public:
        explicit Array2Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ArrayType = Array2<int>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void Array2Test();
        void InitArray(ArrayType& array2);
        void ResultTest(const ArrayType& array2);

    private:
        static constexpr auto bound0 = 5;
        static constexpr auto bound1 = 10;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_ARRAY2_TESTING_H