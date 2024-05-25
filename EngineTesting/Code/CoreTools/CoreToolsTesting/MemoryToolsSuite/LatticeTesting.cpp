/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/15 21:28)

#include "LatticeTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/LatticeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LatticeTesting::LatticeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LatticeTesting)

void CoreTools::LatticeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LatticeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoordinateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToLTest);
}

void CoreTools::LatticeTesting::SizeTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Size0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Size1Test);
}

void CoreTools::LatticeTesting::Size0Test()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    static_assert(lattice.GetDimensions() == 3);

    ASSERT_EQUAL(lattice.GetSize(0), latticeSize0);
    ASSERT_EQUAL(lattice.GetSize(1), latticeSize1);
    ASSERT_EQUAL(lattice.GetSize(2), latticeSize2);

    static_assert(lattice.GetSize() == latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::LatticeTesting::Size1Test()
{
    const Lattice<true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    ASSERT_EQUAL(lattice.GetDimensions(), 3);

    ASSERT_EQUAL(lattice.GetSize(0), latticeSize0);
    ASSERT_EQUAL(lattice.GetSize(1), latticeSize1);
    ASSERT_EQUAL(lattice.GetSize(2), latticeSize2);

    ASSERT_EQUAL(lattice.GetSize(), latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::LatticeTesting::GetIndexTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex3Test);
}

void CoreTools::LatticeTesting::GetIndex0Test()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex(index0, index1, index2);

    ASSERT_EQUAL(index, index0 + latticeSize0 * (index1 + latticeSize1 * index2));
}

void CoreTools::LatticeTesting::GetIndex1Test()
{
    constexpr Lattice<false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex(index0, index1, index2);

    ASSERT_EQUAL(index, index2 + latticeSize2 * (index1 + latticeSize1 * index0));
}

void CoreTools::LatticeTesting::GetIndex2Test()
{
    const Lattice<true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto index = lattice.GetIndex(index0, index1, index2);

    ASSERT_EQUAL(index, index0 + latticeSize0 * (index1 + latticeSize1 * index2));
}

void CoreTools::LatticeTesting::GetIndex3Test()
{
    const Lattice<false> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto index = lattice.GetIndex(index0, index1, index2);

    ASSERT_EQUAL(index, index2 + latticeSize2 * (index1 + latticeSize1 * index0));
}

void CoreTools::LatticeTesting::GetIndexArrayTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray3Test);
}

void CoreTools::LatticeTesting::GetIndexArray0Test()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex({ index3, index4, index5 });

    ASSERT_EQUAL(index, index3 + latticeSize0 * (index4 + latticeSize1 * index5));
}

void CoreTools::LatticeTesting::GetIndexArray1Test()
{
    constexpr Lattice<false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex({ index3, index4, index5 });

    ASSERT_EQUAL(index, index5 + latticeSize2 * (index4 + latticeSize1 * index3));
}

void CoreTools::LatticeTesting::GetIndexArray2Test()
{
    const Lattice<true> lattice{ Lattice<true>::SizeType{ latticeSize0, latticeSize1, latticeSize2 } };

    const auto index = lattice.GetIndex({ index3, index4, index5 });

    ASSERT_EQUAL(index, index3 + latticeSize0 * (index4 + latticeSize1 * index5));
}

void CoreTools::LatticeTesting::GetIndexArray3Test()
{
    const Lattice<false> lattice3{ Lattice<false>::SizeType{ latticeSize0, latticeSize1, latticeSize2 } };

    const auto index = lattice3.GetIndex({ index3, index4, index5 });

    ASSERT_EQUAL(index, index5 + latticeSize2 * (index4 + latticeSize1 * index3));
}

void CoreTools::LatticeTesting::CoordinateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate3Test);
}

void CoreTools::LatticeTesting::Coordinate0Test()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto coordinate = lattice.GetCoordinate<>(index6);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, index6);
}

void CoreTools::LatticeTesting::Coordinate1Test()
{
    constexpr Lattice<false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto coordinate = lattice.GetCoordinate<>(index7);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, index7);
}

void CoreTools::LatticeTesting::Coordinate2Test()
{
    const Lattice<true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto coordinate = lattice.GetCoordinate<>(index6);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, index6);
}

void CoreTools::LatticeTesting::Coordinate3Test()
{
    const Lattice<false> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto coordinate = lattice.GetCoordinate<>(index7);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, index7);
}

void CoreTools::LatticeTesting::OrderLToRTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToR0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToR1Test);
}

void CoreTools::LatticeTesting::OrderLToR0Test()
{
    const LatticeType0 lattice{};

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRIndex0Test, lattice);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRSize0Test, lattice);
}

void CoreTools::LatticeTesting::OrderLToRIndex0Test(const LatticeType0& lattice)
{
    for (auto x2 = 0, i = 0; x2 < lattice.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < lattice.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice.GetSize(0); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice.GetIndex(x0, x1, x2), i);

                const std::array x{ x0, x1, x2 };
                ASSERT_EQUAL(lattice.GetIndex(x), i);
            }
        }
    }
}

void CoreTools::LatticeTesting::OrderLToRSize0Test(const LatticeType0& lattice)
{
    for (auto i = 0; i < lattice.GetSize(); ++i)
    {
        const auto x = lattice.GetCoordinate(i);

        ASSERT_EQUAL(x.at(0), i % latticeSize3);
        ASSERT_EQUAL(x.at(1), (i / latticeSize3) % latticeSize4);
        ASSERT_EQUAL(x.at(2), (i / latticeSize3) / latticeSize4);
    }
}

void CoreTools::LatticeTesting::OrderLToR1Test()
{
    const Lattice<true> lattice{ latticeSize3, latticeSize4, latticeSize5 };

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRIndex1Test, lattice);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRSize1Test, lattice);
}

void CoreTools::LatticeTesting::OrderLToRIndex1Test(const LatticeType1& lattice)
{
    for (auto x2 = 0, i = 0; x2 < lattice.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < lattice.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice.GetSize(0); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice.GetIndex(x0, x1, x2), i);

                const std::vector x{ x0, x1, x2 };
                ASSERT_EQUAL(lattice.GetIndex(x), i);
            }
        }
    }
}

void CoreTools::LatticeTesting::OrderLToRSize1Test(const LatticeType1& lattice)
{
    for (auto i = 0; i < lattice.GetSize(); ++i)
    {
        const auto x = lattice.GetCoordinate(i);

        ASSERT_EQUAL(x.at(0), i % latticeSize3);
        ASSERT_EQUAL(x.at(1), (i / latticeSize3) % latticeSize4);
        ASSERT_EQUAL(x.at(2), (i / latticeSize3) / latticeSize4);
    }
}

void CoreTools::LatticeTesting::OrderRToLTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToL0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToL1Test);
}

void CoreTools::LatticeTesting::OrderRToL0Test()
{
    const LatticeType2 lattice{};

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLIndex0Test, lattice);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLSize0Test, lattice);
}

void CoreTools::LatticeTesting::OrderRToLIndex0Test(const LatticeType2& lattice)
{
    for (auto x2 = 0, i = 0; x2 < lattice.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < lattice.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice.GetSize(2); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice.GetIndex(x2, x1, x0), i);

                const std::array x{ x2, x1, x0 };
                ASSERT_EQUAL(lattice.GetIndex(x), i);
            }
        }
    }
}

void CoreTools::LatticeTesting::OrderRToLSize0Test(const LatticeType2& lattice)
{
    for (auto i = 0; i < lattice.GetSize(); ++i)
    {
        const auto x = lattice.GetCoordinate(i);

        ASSERT_EQUAL(x.at(2), i % latticeSize5);
        ASSERT_EQUAL(x.at(1), (i / latticeSize5) % latticeSize4);
        ASSERT_EQUAL(x.at(0), (i / latticeSize5) / latticeSize4);
    }
}

void CoreTools::LatticeTesting::OrderRToL1Test()
{
    const LatticeType3 lattice{ latticeSize3, latticeSize4, latticeSize5 };

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLIndex1Test, lattice);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLSize1Test, lattice);
}

void CoreTools::LatticeTesting::OrderRToLIndex1Test(const LatticeType3& lattice)
{
    for (auto x2 = 0, i = 0; x2 < lattice.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < lattice.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice.GetSize(2); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice.GetIndex(x2, x1, x0), i);

                const std::vector x{ x2, x1, x0 };
                ASSERT_EQUAL(lattice.GetIndex(x), i);
            }
        }
    }
}

void CoreTools::LatticeTesting::OrderRToLSize1Test(const LatticeType3& lattice)
{
    for (auto i = 0; i < lattice.GetSize(); ++i)
    {
        const auto x = lattice.GetCoordinate(i);

        ASSERT_EQUAL(x.at(2), i % latticeSize5);
        ASSERT_EQUAL(x.at(1), (i / latticeSize5) % latticeSize4);
        ASSERT_EQUAL(x.at(0), (i / latticeSize5) / latticeSize4);
    }
}