/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/15 22:03)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LATTICE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LATTICE_TESTING_H

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LatticeTesting final : public UnitTest
    {
    public:
        using ClassType = LatticeTesting;
        using ParentType = UnitTest;

    public:
        explicit LatticeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto latticeSize0 = 5;
        static constexpr auto latticeSize1 = 6;
        static constexpr auto latticeSize2 = 10;

        static constexpr auto latticeSize3 = 2;
        static constexpr auto latticeSize4 = 3;
        static constexpr auto latticeSize5 = 5;

        static constexpr auto index0 = 1;
        static constexpr auto index1 = 2;
        static constexpr auto index2 = 3;

        static constexpr auto index3 = 4;
        static constexpr auto index4 = 7;
        static constexpr auto index5 = 8;

        static constexpr auto index6 = 6;
        static constexpr auto index7 = 61;

        using LatticeType0 = Lattice<true, latticeSize3, latticeSize4, latticeSize5>;
        using LatticeType1 = Lattice<true>;
        using LatticeType2 = Lattice<false, latticeSize3, latticeSize4, latticeSize5>;
        using LatticeType3 = Lattice<false>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SizeTest();
        void GetIndexTest();
        void GetIndexArrayTest();
        void CoordinateTest();
        void OrderLToRTest();
        void OrderRToLTest();

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
        void OrderRToL0Test();
        void OrderRToL1Test();

        void OrderLToRIndex0Test(const LatticeType0& lattice);
        void OrderLToRSize0Test(const LatticeType0& lattice);
        void OrderLToRIndex1Test(const LatticeType1& lattice);
        void OrderLToRSize1Test(const LatticeType1& lattice);
        void OrderRToLIndex0Test(const LatticeType2& lattice);
        void OrderRToLSize0Test(const LatticeType2& lattice);
        void OrderRToLIndex1Test(const LatticeType3& lattice);
        void OrderRToLSize1Test(const LatticeType3& lattice);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LATTICE_TESTING_H