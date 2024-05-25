/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/17 23:46)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_TESTING_H

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MultiArrayTesting final : public UnitTest
    {
    public:
        using ClassType = MultiArrayTesting;
        using ParentType = UnitTest;

    public:
        explicit MultiArrayTesting(const OStreamShared& stream);

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

        static constexpr auto original = 1.0f;
        static constexpr auto increase = 2.0f;

        using MultiArrayType0 = MultiArray<int, true>;
        using MultiArrayType1 = MultiArray<float, true, latticeSize6, latticeSize7, latticeSize8>;
        using MultiArrayType2 = MultiArray<float, true>;
        using MultiArrayType3 = MultiArray<int, false>;
        using MultiArrayType4 = MultiArray<float, false, latticeSize6, latticeSize7, latticeSize8>;
        using MultiArrayType5 = MultiArray<float, false>;
        using MultiArrayType6 = MultiArray<int, true, latticeSize0, latticeSize1, latticeSize5>;
        using MultiArrayType7 = MultiArray<int, false, latticeSize0, latticeSize1, latticeSize5>;

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

        void CompareTest();

        void Size0Test();
        void Size1Test();
        void GetIndex0Test();
        void GetIndex1Test();
        void GetIndex2Test();
        void GetIndex3Test();
        void GetIndexArray0Test();
        void GetIndexArray1Test();
        void GetIndexArray2Test();
        void GetIndexArray3Test();
        void Coordinate0Test();
        void Coordinate1Test();
        void Coordinate2Test();
        void Coordinate3Test();
        void OrderLToR0Test();
        void OrderLToR1Test();
        void OrderLToR2Test();

        void OrderLToR0FillTest(MultiArrayType0& multiArray);
        void OrderLToR0ValueTest(MultiArrayType0& multiArray);
        void OrderLToR1InitTest(MultiArrayType1& multiArray);
        void OrderLToR1ResultTest(MultiArrayType1& multiArray, float step);
        void OrderLToR2InitTest(MultiArrayType2& multiArray);
        void OrderLToR2ResultTest(MultiArrayType2& multiArray, float step);
        void OrderRToL0Test();
        void OrderRToL1Test();
        void OrderRToL2Test();
        void OrderRToL0FillTest(MultiArrayType3& multiArray);
        void OrderRToL0ValueTest(MultiArrayType3& multiArray);
        void OrderRToL1InitTest(MultiArrayType4& multiArray);
        void OrderRToL1ResultTest(MultiArrayType4& multiArray, float step);
        void OrderRToL2InitTest(MultiArrayType5& multiArray);
        void OrderRToL2ResultTest(MultiArrayType5& multiArray, float step);
        void OrderLToRConstantFillTest(MultiArrayType6& multiArray);
        void OrderLToRConstantValueTest(MultiArrayType6& multiArray);
        void OrderRToLConstantFillTest(MultiArrayType7& multiArray);
        void OrderRToLConstantValueTest(MultiArrayType7& multiArray);
        void Compare0Test();
        void Compare1Test();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_TESTING_H