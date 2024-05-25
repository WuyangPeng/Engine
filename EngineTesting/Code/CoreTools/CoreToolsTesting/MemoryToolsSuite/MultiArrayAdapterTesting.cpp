/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/17 20:08)

#include "MultiArrayAdapterTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/MultiArrayAdapterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <numeric>

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
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToLTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToRConstantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToLConstantTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MultiArrayAdapterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResetTest);
}

void CoreTools::MultiArrayAdapterTesting::SizeTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(Size0Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(Size1Test, container);
}

void CoreTools::MultiArrayAdapterTesting::Size0Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> multiArrayAdapter{ container.data() };

    static_assert(multiArrayAdapter.GetDimensions() == 3);

    ASSERT_EQUAL(multiArrayAdapter.GetSize(0), latticeSize0);
    ASSERT_EQUAL(multiArrayAdapter.GetSize(1), latticeSize1);
    ASSERT_EQUAL(multiArrayAdapter.GetSize(2), latticeSize2);

    static_assert(multiArrayAdapter.GetSize() == latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::MultiArrayAdapterTesting::Size1Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true> multiArrayAdapter{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    ASSERT_EQUAL(multiArrayAdapter.GetDimensions(), 3);

    ASSERT_EQUAL(multiArrayAdapter.GetSize(0), latticeSize0);
    ASSERT_EQUAL(multiArrayAdapter.GetSize(1), latticeSize1);
    ASSERT_EQUAL(multiArrayAdapter.GetSize(2), latticeSize2);

    ASSERT_EQUAL(multiArrayAdapter.GetSize(), latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::MultiArrayAdapterTesting::GetIndexTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(GetIndex0Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndex1Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndex2Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndex3Test, container);
}

void CoreTools::MultiArrayAdapterTesting::GetIndex0Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple0 + latticeSize0 * (tuple1 + latticeSize1 * tuple2));
}

void CoreTools::MultiArrayAdapterTesting::GetIndex1Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple2 + latticeSize2 * (tuple1 + latticeSize1 * tuple0));
}

void CoreTools::MultiArrayAdapterTesting::GetIndex2Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple0 + latticeSize0 * (tuple1 + latticeSize1 * tuple2));
}

void CoreTools::MultiArrayAdapterTesting::GetIndex3Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple2 + latticeSize2 * (tuple1 + latticeSize1 * tuple0));
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArrayTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(GetIndexArray0Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndexArray1Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndexArray2Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(GetIndexArray3Test, container);
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArray0Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize3 + latticeSize0 * (latticeSize4 + latticeSize1 * latticeSize5));
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArray1Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize5 + latticeSize2 * (latticeSize4 + latticeSize1 * latticeSize3));
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArray2Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true> lattice{ MultiArrayAdapter<int, true>::SizeType{ latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize3 + latticeSize0 * (latticeSize4 + latticeSize1 * latticeSize5));
}

void CoreTools::MultiArrayAdapterTesting::GetIndexArray3Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false> lattice{ MultiArrayAdapter<int, false>::SizeType{ latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize5 + latticeSize2 * (latticeSize4 + latticeSize1 * latticeSize3));
}

void CoreTools::MultiArrayAdapterTesting::CoordinateTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(Coordinate0Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(Coordinate1Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(Coordinate2Test, container);
    ASSERT_NOT_THROW_EXCEPTION_1(Coordinate3Test, container);
}

void CoreTools::MultiArrayAdapterTesting::Coordinate0Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto coordinate = lattice.GetCoordinate<>(tuple3);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple3);
}

void CoreTools::MultiArrayAdapterTesting::Coordinate1Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    const auto coordinate = lattice.GetCoordinate<>(tuple4);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple4);
}

void CoreTools::MultiArrayAdapterTesting::Coordinate2Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto coordinate = lattice.GetCoordinate<>(tuple3);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple3);
}

void CoreTools::MultiArrayAdapterTesting::Coordinate3Test(ContainerType& container)
{
    const MultiArrayAdapter<int, false> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    const auto coordinate = lattice.GetCoordinate<>(tuple4);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple4);
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    MultiArrayAdapterType0 multiArray{ { latticeSize0, latticeSize1, latticeSize5 }, container.data() };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRValueTest, multiArray);
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRFillTest(MultiArrayAdapterType0& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRValueTest(MultiArrayAdapterType0& multiArray)
{
    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < latticeSize5; ++i0)
    {
        for (auto i1 = 0; i1 < latticeSize1; ++i1)
        {
            for (auto i2 = 0; i2 < latticeSize0; ++i2)
            {
                ASSERT_EQUAL(multiArray(i2, i1, i0), index);
                ASSERT_EQUAL(multiArray({ i2, i1, i0 }), index);
                ++index;
            }
        }
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    MultiArrayAdapterType1 multiArray{ { latticeSize0, latticeSize1, latticeSize5 }, container.data() };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLValueTest, multiArray);
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLFillTest(MultiArrayAdapterType1& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLValueTest(MultiArrayAdapterType1& multiArray)
{
    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] = i;
    }

    auto index = 0;
    for (auto i0 = 0; i0 < latticeSize0; ++i0)
    {
        for (auto i1 = 0; i1 < latticeSize1; ++i1)
        {
            for (auto i2 = 0; i2 < latticeSize5; ++i2)
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
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    MultiArrayAdapterType2 multiArray{ container.data() };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRConstantFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRConstantValueTest, multiArray);
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRConstantFillTest(MultiArrayAdapterType2& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
        multiArray[i] = i;
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderLToRConstantValueTest(MultiArrayAdapterType2& multiArray)
{
    auto index = 0;
    for (auto i0 = 0; i0 < latticeSize5; ++i0)
    {
        for (auto i1 = 0; i1 < latticeSize1; ++i1)
        {
            for (auto i2 = 0; i2 < latticeSize0; ++i2)
            {
                ASSERT_EQUAL(multiArray(i2, i1, i0), index);
                ASSERT_EQUAL(multiArray({ i2, i1, i0 }), index);
                ++index;
            }
        }
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLConstantTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    MultiArrayAdapterType3 multiArray{ container.data() };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLConstantFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLConstantValueTest, multiArray);
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLConstantFillTest(MultiArrayAdapterType3& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
        multiArray[i] = i;
    }
}

void CoreTools::MultiArrayAdapterTesting::OrderRToLConstantValueTest(MultiArrayAdapterType3& multiArray)
{
    auto index = 0;
    for (auto i0 = 0; i0 < latticeSize0; ++i0)
    {
        for (auto i1 = 0; i1 < latticeSize1; ++i1)
        {
            for (auto i2 = 0; i2 < latticeSize5; ++i2)
            {
                ASSERT_EQUAL(multiArray(i0, i1, i2), index);
                ASSERT_EQUAL(multiArray({ i0, i1, i2 }), index);
                ++index;
            }
        }
    }
}

void CoreTools::MultiArrayAdapterTesting::MultiArrayAdapterTest()
{
    std::array<int, latticeSize6 * latticeSize7 * latticeSize8> storage{};
    std::iota(storage.begin(), storage.end(), 1);

    const MultiArrayAdapter<int, true, latticeSize6, latticeSize7, latticeSize8> multiArray{ storage.data() };

    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(0); ++x0, ++i)
            {
                ASSERT_EQUAL(multiArray(x0, x1, x2), i + 1);

                const std::array x{ x0, x1, x2 };

                ASSERT_EQUAL(multiArray(x), i + 1);
            }
        }
    }
}

void CoreTools::MultiArrayAdapterTesting::CompareTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(Compare0Test, container);

    ASSERT_NOT_THROW_EXCEPTION_1(Compare1Test, container);
}

void CoreTools::MultiArrayAdapterTesting::Compare0Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{ container.data() };

    ASSERT_TRUE(lattice == lattice);
    ASSERT_FALSE(lattice != lattice);

    ASSERT_FALSE(lattice < lattice);
    ASSERT_FALSE(lattice > lattice);
    ASSERT_TRUE(lattice <= lattice);
    ASSERT_TRUE(lattice >= lattice);
}

void CoreTools::MultiArrayAdapterTesting::Compare1Test(ContainerType& container)
{
    const MultiArrayAdapter<int, true> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container.data() };

    ASSERT_TRUE(lattice == lattice);
    ASSERT_FALSE(lattice != lattice);

    ASSERT_FALSE(lattice < lattice);
    ASSERT_FALSE(lattice > lattice);
    ASSERT_TRUE(lattice <= lattice);
    ASSERT_TRUE(lattice >= lattice);
}

void CoreTools::MultiArrayAdapterTesting::ResetTest()
{
    constexpr Lattice<true, latticeSize0, latticeSize1, latticeSize2> lattice{};
    ContainerType container0(lattice.GetSize());
    ContainerType container1(lattice.GetSize());

    ASSERT_NOT_THROW_EXCEPTION_2(Reset0Test, container0, container1);
    ASSERT_NOT_THROW_EXCEPTION_2(Reset1Test, container0, container1);
}

void CoreTools::MultiArrayAdapterTesting::Reset0Test(ContainerType& container0, ContainerType& container1)
{
    MultiArrayAdapter<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{ container0.data() };
    lattice.Reset(container1.data());
}

void CoreTools::MultiArrayAdapterTesting::Reset1Test(ContainerType& container0, ContainerType& container1)
{
    MultiArrayAdapter<int, true> lattice{ { latticeSize0, latticeSize1, latticeSize2 }, container0.data() };
    lattice.Reset({ latticeSize0, latticeSize1, latticeSize2 }, container1.data());
}