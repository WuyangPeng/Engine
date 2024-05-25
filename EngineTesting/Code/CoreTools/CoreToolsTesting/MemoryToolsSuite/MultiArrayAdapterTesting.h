/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/17 20:26)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MultiArrayAdapterTesting final : public UnitTest
    {
    public:
        using ClassType = MultiArrayAdapterTesting;
        using ParentType = UnitTest;

    public:
        explicit MultiArrayAdapterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto latticeSize0 = 5;
        static constexpr auto latticeSize1 = 6;
        static constexpr auto latticeSize2 = 10;

        static constexpr auto latticeSize3 = 4;
        static constexpr auto latticeSize4 = 7;
        static constexpr auto latticeSize5 = 8;

        static constexpr auto latticeSize6 = 2;
        static constexpr auto latticeSize7 = 3;
        static constexpr auto latticeSize8 = 5;

        static constexpr auto tuple0 = 1;
        static constexpr auto tuple1 = 2;
        static constexpr auto tuple2 = 3;

        static constexpr auto tuple3 = 6;
        static constexpr auto tuple4 = 61;
        static constexpr auto tuple5 = 5;

        using ContainerType = std::vector<int>;
        using MultiArrayAdapterType0 = MultiArrayAdapter<int, true>;
        using MultiArrayAdapterType1 = MultiArrayAdapter<int, false>;
        using MultiArrayAdapterType2 = MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize5>;
        using MultiArrayAdapterType3 = MultiArrayAdapter<int, false, latticeSize0, latticeSize1, latticeSize5>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SizeTest();
        void GetIndexTest();
        void GetIndexArrayTest();
        void CoordinateTest();

        void OrderLToRTest();
        void OrderRToLTest();
        void OrderLToRConstantTest();
        void OrderRToLConstantTest();

        void MultiArrayAdapterTest();
        void CompareTest();
        void ResetTest();

        void Size0Test(ContainerType& container);
        void Size1Test(ContainerType& container);
        void GetIndex0Test(ContainerType& container);
        void GetIndex1Test(ContainerType& container);
        void GetIndex2Test(ContainerType& container);
        void GetIndex3Test(ContainerType& container);
        void GetIndexArray0Test(ContainerType& container);
        void GetIndexArray1Test(ContainerType& container);
        void GetIndexArray2Test(ContainerType& container);
        void GetIndexArray3Test(ContainerType& container);
        void Coordinate0Test(ContainerType& container);
        void Coordinate1Test(ContainerType& container);
        void Coordinate2Test(ContainerType& container);
        void Coordinate3Test(ContainerType& container);

        void OrderLToRFillTest(MultiArrayAdapterType0& multiArray);
        void OrderLToRValueTest(MultiArrayAdapterType0& multiArray);
        void OrderRToLFillTest(MultiArrayAdapterType1& multiArray);
        void OrderRToLValueTest(MultiArrayAdapterType1& multiArray);
        void OrderLToRConstantFillTest(MultiArrayAdapterType2& multiArray);
        void OrderLToRConstantValueTest(MultiArrayAdapterType2& multiArray);
        void OrderRToLConstantFillTest(MultiArrayAdapterType3& multiArray);
        void OrderRToLConstantValueTest(MultiArrayAdapterType3& multiArray);

        void Compare0Test(ContainerType& container);
        void Compare1Test(ContainerType& container);
        void Reset0Test(ContainerType& container0, ContainerType& container1);
        void Reset1Test(ContainerType& container0, ContainerType& container1);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H