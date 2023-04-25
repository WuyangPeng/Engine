///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/14 11:08)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_ARRAY4_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_ARRAY4_TESTING_H

#include "CoreTools/MemoryTools/Array4.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class Array4Testing final : public UnitTest
    {
    public:
        using ClassType = Array4Testing;
        using ParentType = UnitTest;

    public:
        explicit Array4Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ArrayType = Array4<int>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void Array4Test();
        void InitArray(ArrayType& array4);
        void ResultTest(const ArrayType& array4);

    private:
        static constexpr auto bound0 = 5;
        static constexpr auto bound1 = 10;
        static constexpr auto bound2 = 7;
        static constexpr auto bound3 = 2;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_ARRAY4_TESTING_H