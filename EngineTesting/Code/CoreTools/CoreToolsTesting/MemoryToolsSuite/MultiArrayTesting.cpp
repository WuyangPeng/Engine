/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:21)

#include "MultiArrayTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/MultiArrayDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

CoreTools::MultiArrayTesting::MultiArrayTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MultiArrayTesting)

void CoreTools::MultiArrayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MultiArrayTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoordinateTest);

    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToLTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToLConstantTest);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void CoreTools::MultiArrayTesting::SizeTest()
{
    const MultiArray<int, true, 5, 6, 10> lattice0{};

    static_assert(lattice0.GetDimensions() == 3);

    ASSERT_EQUAL(lattice0.GetSize(0), 5);
    ASSERT_EQUAL(lattice0.GetSize(1), 6);
    ASSERT_EQUAL(lattice0.GetSize(2), 10);

    static_assert(lattice0.GetSize() == 5 * 6 * 10);

    const MultiArray<int, true> lattice1{ 5, 6, 10 };

    ASSERT_EQUAL(lattice1.GetDimensions(), 3);

    ASSERT_EQUAL(lattice1.GetSize(0), 5);
    ASSERT_EQUAL(lattice1.GetSize(1), 6);
    ASSERT_EQUAL(lattice1.GetSize(2), 10);

    ASSERT_EQUAL(lattice1.GetSize(), 5 * 6 * 10);
}

void CoreTools::MultiArrayTesting::GetIndexTest()
{
    const MultiArray<int, true, 5, 6, 10> lattice0{};

    const auto index0 = lattice0.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index0, 1 + 5 * (2 + 6 * 3));

    const MultiArray<int, false, 5, 6, 10> lattice1{};

    const auto index1 = lattice1.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index1, 3 + 10 * (2 + 6 * 1));

    const MultiArray<int, true> lattice2{ 5, 6, 10 };

    const auto index2 = lattice2.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index2, 1 + 5 * (2 + 6 * 3));

    const MultiArray<int, false> lattice3{ 5, 6, 10 };

    const auto index3 = lattice3.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index3, 3 + 10 * (2 + 6 * 1));
}

void CoreTools::MultiArrayTesting::GetIndexArrayTest()
{
    const MultiArray<int, true, 5, 6, 10> lattice0{};

    const auto index0 = lattice0.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index0, 4 + 5 * (7 + 6 * 8));

    const MultiArray<int, false, 5, 6, 10> lattice1{};

    const auto index1 = lattice1.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index1, 8 + 10 * (7 + 6 * 4));

    const MultiArray<int, true> lattice2{ MultiArray<int, true>::SizeType{ 5, 6, 10 } };

    const auto index2 = lattice2.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index2, 4 + 5 * (7 + 6 * 8));

    const MultiArray<int, false> lattice3{ MultiArray<int, false>::SizeType{ 5, 6, 10 } };

    const auto index3 = lattice3.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index3, 8 + 10 * (7 + 6 * 4));
}

void CoreTools::MultiArrayTesting::CoordinateTest()
{
    const MultiArray<int, true, 5, 6, 10> lattice0{};

    const auto coordinate0 = lattice0.GetCoordinate<>(6);

    const auto index0 = lattice0.GetIndex(coordinate0);

    ASSERT_EQUAL(index0, 6);

    const MultiArray<int, false, 5, 6, 10> lattice1{};

    const auto coordinate1 = lattice1.GetCoordinate<>(61);

    const auto index1 = lattice1.GetIndex(coordinate1);

    ASSERT_EQUAL(index1, 61);

    const MultiArray<int, true> lattice2{ 5, 6, 10 };

    const auto coordinate2 = lattice2.GetCoordinate<>(6);

    const auto index2 = lattice2.GetIndex(coordinate2);

    ASSERT_EQUAL(index2, 6);

    const MultiArray<int, false> lattice3{ 5, 6, 10 };

    const auto coordinate3 = lattice2.GetCoordinate<>(61);

    const auto index3 = lattice2.GetIndex(coordinate3);

    ASSERT_EQUAL(index3, 61);
}

void CoreTools::MultiArrayTesting::OrderLToRTest()
{
    MultiArray<int, true> multiArray0{ 5, 6, 8 };

    ASSERT_UNEQUAL_NULL_PTR(multiArray0.GetData());

    multiArray0.Fill(5);

    for (auto i = 0; i < multiArray0.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray0[i], 5);
        multiArray0[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < 8; ++i0)
    {
        for (auto i1 = 0; i1 < 6; ++i1)
        {
            for (auto i2 = 0; i2 < 5; ++i2)
            {
                ASSERT_EQUAL(multiArray0(i2, i1, i0), index);
                ASSERT_EQUAL(multiArray0({ i2, i1, i0 }), index);
                ++index;
            }
        }
    }

    MultiArray<float, true, 2, 3, 5> multiArray1{};

    for (auto x2 = 0, i = 0; x2 < multiArray1.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray1.GetSize(0); ++x0, ++i)
            {
                multiArray1(x0, x1, x2) = static_cast<float>(i + 1);
            }
        }
    }

    for (auto i = 0; i < multiArray1.GetSize(); ++i)
    {
        multiArray1[i] += 2.0f;
    }

    for (auto x2 = 0, i = 0; x2 < multiArray1.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray1.GetSize(0); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray1(x0, x1, x2), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());

                const std::array x{ x0, x1, x2 };

                ASSERT_APPROXIMATE(multiArray1(x), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());
            }
        }
    }

    MultiArray<float, true> multiArray2{ 2, 3, 5 };

    for (auto x2 = 0, i = 0; x2 < multiArray2.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray2.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray2.GetSize(0); ++x0, ++i)
            {
                multiArray2(x0, x1, x2) = static_cast<float>(i + 1);
            }
        }
    }

    for (auto i = 0; i < multiArray2.GetSize(); ++i)
    {
        multiArray2[i] += 2.0f;
    }

    for (auto x2 = 0, i = 0; x2 < multiArray2.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray2.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray2.GetSize(0); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray2(x0, x1, x2), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());

                const std::vector x{ x0, x1, x2 };

                ASSERT_APPROXIMATE(multiArray2(x), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToLTest()
{
    MultiArray<int, false> multiArray0{ 5, 6, 8 };

    ASSERT_UNEQUAL_NULL_PTR(multiArray0.GetData());

    multiArray0.Fill(5);

    for (auto i = 0; i < multiArray0.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray0[i], 5);
        multiArray0[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < 5; ++i0)
    {
        for (auto i1 = 0; i1 < 6; ++i1)
        {
            for (auto i2 = 0; i2 < 8; ++i2)
            {
                ASSERT_EQUAL(multiArray0(i0, i1, i2), index);
                ASSERT_EQUAL(multiArray0({ i0, i1, i2 }), index);
                ++index;
            }
        }
    }

    MultiArray<float, false, 2, 3, 5> multiArray1{};

    for (auto x2 = 0, i = 0; x2 < multiArray1.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray1.GetSize(2); ++x0, ++i)
            {
                multiArray1(x2, x1, x0) = static_cast<float>(i + 1);
            }
        }
    }

    for (auto i = 0; i < multiArray1.GetSize(); ++i)
    {
        multiArray1[i] += 2.0f;
    }

    for (auto x2 = 0, i = 0; x2 < multiArray1.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray1.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray1.GetSize(2); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray1(x2, x1, x0), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());

                const std::array x{ x2, x1, x0 };

                ASSERT_APPROXIMATE(multiArray1(x), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());
            }
        }
    }

    MultiArray<float, false> multiArray2{ 2, 3, 5 };

    for (auto x2 = 0, i = 0; x2 < multiArray2.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray2.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray2.GetSize(2); ++x0, ++i)
            {
                multiArray2(x2, x1, x0) = static_cast<float>(i + 1);
            }
        }
    }

    for (auto i = 0; i < multiArray2.GetSize(); ++i)
    {
        multiArray2[i] += 2.0f;
    }

    for (auto x2 = 0, i = 0; x2 < multiArray2.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray2.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray2.GetSize(2); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray2(x2, x1, x0), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());

                const std::vector x{ x2, x1, x0 };

                ASSERT_APPROXIMATE(multiArray2(x), static_cast<float>(i + 3), Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderLToRConstantTest()
{
    MultiArray<int, true, 5, 6, 8> multiArray{};

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    multiArray.Fill(5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], 5);
        multiArray[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < 8; ++i0)
    {
        for (auto i1 = 0; i1 < 6; ++i1)
        {
            for (auto i2 = 0; i2 < 5; ++i2)
            {
                ASSERT_EQUAL(multiArray(i2, i1, i0), index);
                ASSERT_EQUAL(multiArray({ i2, i1, i0 }), index);
                ++index;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToLConstantTest()
{
    MultiArray<int, false, 5, 6, 8> multiArray{};

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    multiArray.Fill(5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], 5);
        multiArray[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < 5; ++i0)
    {
        for (auto i1 = 0; i1 < 6; ++i1)
        {
            for (auto i2 = 0; i2 < 8; ++i2)
            {
                ASSERT_EQUAL(multiArray(i0, i1, i2), index);
                ASSERT_EQUAL(multiArray({ i0, i1, i2 }), index);
                ++index;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::CompareTest()
{
    const MultiArray<int, true, 5, 6, 10> lattice0{};

    ASSERT_TRUE(lattice0 == lattice0);
    ASSERT_FALSE(lattice0 != lattice0);

    ASSERT_FALSE(lattice0 < lattice0);
    ASSERT_FALSE(lattice0 > lattice0);
    ASSERT_TRUE(lattice0 <= lattice0);
    ASSERT_TRUE(lattice0 >= lattice0);

    const MultiArray<int, true> lattice1{ 5, 6, 10 };

    ASSERT_TRUE(lattice1 == lattice1);
    ASSERT_FALSE(lattice1 != lattice1);

    ASSERT_FALSE(lattice1 < lattice1);
    ASSERT_FALSE(lattice1 > lattice1);
    ASSERT_TRUE(lattice1 <= lattice1);
    ASSERT_TRUE(lattice1 >= lattice1);
}
