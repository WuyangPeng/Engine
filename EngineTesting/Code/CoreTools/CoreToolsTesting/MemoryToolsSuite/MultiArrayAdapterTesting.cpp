﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/17 15:44)

#include "MultiArrayAdapterTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/MultiArrayAdapterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MultiArrayAdapterTesting::MultiArrayAdapterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MultiArrayAdapterTesting)

void CoreTools::MultiArrayAdapterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MultiArrayAdapterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoordinateTest);

    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLRoTTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLRoTConstantTest);
}

void CoreTools::MultiArrayAdapterTesting::SizeTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    const MultiArrayAdapter<int, true, 5, 6, 10> lattice0{ container.data() };

    static_assert(lattice0.GetDimensions() == 3);

    static_assert(lattice0.GetSize(0) == 5);
    static_assert(lattice0.GetSize(1) == 6);
    static_assert(lattice0.GetSize(2) == 10);

    static_assert(lattice0.GetSize() == 5 * 6 * 10);

    const MultiArrayAdapter<int, true> lattice1{ { 5, 6, 10 }, container.data() };

    ASSERT_EQUAL(lattice1.GetDimensions(), 3);

    ASSERT_EQUAL(lattice1.GetSize(0), 5);
    ASSERT_EQUAL(lattice1.GetSize(1), 6);
    ASSERT_EQUAL(lattice1.GetSize(2), 10);

    ASSERT_EQUAL(lattice1.GetSize(), 5 * 6 * 10);
}

void CoreTools::MultiArrayAdapterTesting::GetIndexTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    const MultiArrayAdapter<int, true, 5, 6, 10> lattice0{ container.data() };

    const auto index0 = lattice0.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index0, 1 + 5 * (2 + 6 * 3));

    const MultiArrayAdapter<int, false, 5, 6, 10> lattice1{ container.data() };

    const auto index1 = lattice1.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index1, 3 + 10 * (2 + 6 * 1));

    const MultiArrayAdapter<int, true> lattice2{ { 5, 6, 10 }, container.data() };

    const auto index2 = lattice2.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index2, 1 + 5 * (2 + 6 * 3));

    const MultiArrayAdapter<int, false> lattice3{ { 5, 6, 10 }, container.data() };

    const auto index3 = lattice3.GetIndex(1, 2, 3);

    ASSERT_EQUAL(index3, 3 + 10 * (2 + 6 * 1));
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArrayTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    const MultiArrayAdapter<int, true, 5, 6, 10> lattice0{ container.data() };

    const auto index0 = lattice0.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index0, 4 + 5 * (7 + 6 * 8));

    const MultiArrayAdapter<int, false, 5, 6, 10> lattice1{ container.data() };

    const auto index1 = lattice1.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index1, 8 + 10 * (7 + 6 * 4));

    const MultiArrayAdapter<int, true> lattice2{ MultiArrayAdapter<int, true>::SizeType{ 5, 6, 10 }, container.data() };

    const auto index2 = lattice2.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index2, 4 + 5 * (7 + 6 * 8));

    const MultiArrayAdapter<int, false> lattice3{ MultiArrayAdapter<int, false>::SizeType{ 5, 6, 10 }, container.data() };

    const auto index3 = lattice3.GetIndex({ 4, 7, 8 });

    ASSERT_EQUAL(index3, 8 + 10 * (7 + 6 * 4));
}

void CoreTools::MultiArrayAdapterTesting::CoordinateTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    const MultiArrayAdapter<int, true, 5, 6, 10> lattice0{ container.data() };

    const auto coordinate0 = lattice0.GetCoordinate<>(6);

    const auto index0 = lattice0.GetIndex(coordinate0);

    ASSERT_EQUAL(index0, 6);

    const MultiArrayAdapter<int, false, 5, 6, 10> lattice1{ container.data() };

    const auto coordinate1 = lattice1.GetCoordinate<>(61);

    const auto index1 = lattice1.GetIndex(coordinate1);

    ASSERT_EQUAL(index1, 61);

    const MultiArrayAdapter<int, true> lattice2{ { 5, 6, 10 }, container.data() };

    const auto coordinate2 = lattice2.GetCoordinate<>(6);

    const auto index2 = lattice2.GetIndex(coordinate2);

    ASSERT_EQUAL(index2, 6);

    const MultiArrayAdapter<int, false> lattice3{ { 5, 6, 10 }, container.data() };

    const auto coordinate3 = lattice2.GetCoordinate<>(61);

    const auto index3 = lattice2.GetIndex(coordinate3);

    ASSERT_EQUAL(index3, 61);
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    MultiArrayAdapter<int, true> multiArray{ { 5, 6, 8 }, container.data() };

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

void CoreTools::MultiArrayAdapterTesting::OrderLRoTTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    MultiArrayAdapter<int, false> multiArray{ { 5, 6, 8 }, container.data() };

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

void CoreTools::MultiArrayAdapterTesting::OrderLToRConstantTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    MultiArrayAdapter<int, true, 5, 6, 8> multiArray{ container.data() };

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

void CoreTools::MultiArrayAdapterTesting::OrderLRoTConstantTest()
{
    constexpr Lattice<true, 5, 6, 10> lattice{};
    std::vector<int> container(lattice.GetSize());

    MultiArrayAdapter<int, false, 5, 6, 8> multiArray{ container.data() };

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