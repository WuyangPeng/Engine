///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/11 15:56)

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
    constexpr Lattice<true, 5, 6, 10> lattice0{};

    static_assert(lattice0.GetDimensions() == 3);

    ASSERT_EQUAL(lattice0.GetSize(0), 5);
    ASSERT_EQUAL(lattice0.GetSize(1), 6);
    ASSERT_EQUAL(lattice0.GetSize(2), 10);

    static_assert(lattice0.GetSize() == 5 * 6 * 10);

    const Lattice<true> lattice1{ 5, 6, 10 };

    ASSERT_EQUAL(lattice1.GetDimensions(), 3);

    ASSERT_EQUAL(lattice1.GetSize(0), 5);
    ASSERT_EQUAL(lattice1.GetSize(1), 6);
    ASSERT_EQUAL(lattice1.GetSize(2), 10);

    ASSERT_EQUAL(lattice1.GetSize(), 5 * 6 * 10);
}

void CoreTools::LatticeTesting::GetIndexTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice0{};

    const auto index0 = lattice0.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index0, 1 + 5 * (2 + 6 * 3));

    constexpr Lattice<false, 5, 6, 10> lattice1{};

    const auto index1 = lattice1.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index1, 3 + 10 * (2 + 6 * 1));

    const Lattice<true> lattice2{ 5, 6, 10 };

    const auto index2 = lattice2.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index2, 1 + 5 * (2 + 6 * 3));

    const Lattice<false> lattice3{ 5, 6, 10 };

    const auto index3 = lattice3.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index3, 3 + 10 * (2 + 6 * 1));
}

void CoreTools::LatticeTesting::GetIndexArrayTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice0{};

    const auto index0 = lattice0.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index0, 4 + 5 * (7 + 6 * 8));

    constexpr Lattice<false, 5, 6, 10> lattice1{};

    const auto index1 = lattice1.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index1, 8 + 10 * (7 + 6 * 4));

    const Lattice<true> lattice2{ Lattice<true>::SizeType{ 5, 6, 10 } };

    const auto index2 = lattice2.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index2, 4 + 5 * (7 + 6 * 8));

    const Lattice<false> lattice3{ Lattice<false>::SizeType{ 5, 6, 10 } };

    const auto index3 = lattice3.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index3, 8 + 10 * (7 + 6 * 4));
}

void CoreTools::LatticeTesting::CoordinateTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice0{};

    const auto coordinate0 = lattice0.GetCoordinate<>(6);

    const auto index0 = lattice0.GetIndex(coordinate0);

    ASSERT_EQUAL(index0, 6);

    constexpr Lattice<false, 5, 6, 10> lattice1{};

    const auto coordinate1 = lattice1.GetCoordinate<>(61);

    const auto index1 = lattice1.GetIndex(coordinate1);

    ASSERT_EQUAL(index1, 61);

    const Lattice<true> lattice2{ 5, 6, 10 };

    const auto coordinate2 = lattice2.GetCoordinate<>(6);

    const auto index2 = lattice2.GetIndex(coordinate2);

    ASSERT_EQUAL(index2, 6);

    const Lattice<false> lattice3{ 5, 6, 10 };

    const auto coordinate3 = lattice2.GetCoordinate<>(61);

    const auto index3 = lattice2.GetIndex(coordinate3);

    ASSERT_EQUAL(index3, 61);
}

void CoreTools::LatticeTesting::OrderLToRTest()
{
    const Lattice<true, 2, 3, 5> lattice0{};

    for (auto x2 = 0, i = 0; x2 < lattice0.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < lattice0.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice0.GetSize(0); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice0.GetIndex(x0, x1, x2), i);

                const std::array x{ x0, x1, x2 };
                ASSERT_EQUAL(lattice0.GetIndex(x), i);
            }
        }
    }

    for (auto i = 0; i < lattice0.GetSize(); ++i)
    {
        const auto x = lattice0.GetCoordinate(i);

        ASSERT_EQUAL(x.at(0), i % 2);
        ASSERT_EQUAL(x.at(1), (i / 2) % 3);
        ASSERT_EQUAL(x.at(2), (i / 2) / 3);
    }

    const Lattice<true> lattice1{ 2, 3, 5 };

    for (auto x2 = 0, i = 0; x2 < lattice1.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < lattice1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice1.GetSize(0); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice1.GetIndex(x0, x1, x2), i);

                const std::vector x{ x0, x1, x2 };
                ASSERT_EQUAL(lattice1.GetIndex(x), i);
            }
        }
    }

    for (auto i = 0; i < lattice1.GetSize(); ++i)
    {
        const auto x = lattice1.GetCoordinate(i);

        ASSERT_EQUAL(x.at(0), i % 2);
        ASSERT_EQUAL(x.at(1), (i / 2) % 3);
        ASSERT_EQUAL(x.at(2), (i / 2) / 3);
    }
}

void CoreTools::LatticeTesting::OrderRToLTest()
{
    const Lattice<false, 2, 3, 5> lattice0{};

    for (auto x2 = 0, i = 0; x2 < lattice0.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < lattice0.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice0.GetSize(2); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice0.GetIndex(x2, x1, x0), i);

                const std::array x{ x2, x1, x0 };
                ASSERT_EQUAL(lattice0.GetIndex(x), i);
            }
        }
    }

    for (auto i = 0; i < lattice0.GetSize(); ++i)
    {
        const auto x = lattice0.GetCoordinate(i);

        ASSERT_EQUAL(x.at(2), i % 5);
        ASSERT_EQUAL(x.at(1), (i / 5) % 3);
        ASSERT_EQUAL(x.at(0), (i / 5) / 3);
    }

    const Lattice<false> lattice1{ 2, 3, 5 };

    for (auto x2 = 0, i = 0; x2 < lattice1.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < lattice1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < lattice1.GetSize(2); ++x0, ++i)
            {
                ASSERT_EQUAL(lattice1.GetIndex(x2, x1, x0), i);

                const std::vector x{ x2, x1, x0 };
                ASSERT_EQUAL(lattice1.GetIndex(x), i);
            }
        }
    }

    for (auto i = 0; i < lattice1.GetSize(); ++i)
    {
        const auto x = lattice1.GetCoordinate(i);

        ASSERT_EQUAL(x.at(2), i % 5);
        ASSERT_EQUAL(x.at(1), (i / 5) % 3);
        ASSERT_EQUAL(x.at(0), (i / 5) / 3);
    }
}
