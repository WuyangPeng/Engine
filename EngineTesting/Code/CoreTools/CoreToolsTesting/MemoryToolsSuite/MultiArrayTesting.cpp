/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/17 21:05)

#include "MultiArrayTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/MultiArrayDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

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
    ASSERT_NOT_THROW_EXCEPTION_0(Size0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Size1Test);
}

void CoreTools::MultiArrayTesting::Size0Test()
{
    const MultiArray<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    static_assert(lattice.GetDimensions() == 3);

    ASSERT_EQUAL(lattice.GetSize(0), latticeSize0);
    ASSERT_EQUAL(lattice.GetSize(1), latticeSize1);
    ASSERT_EQUAL(lattice.GetSize(2), latticeSize2);

    static_assert(lattice.GetSize() == latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::MultiArrayTesting::Size1Test()
{
    const MultiArray<int, true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    ASSERT_EQUAL(lattice.GetDimensions(), 3);

    ASSERT_EQUAL(lattice.GetSize(0), latticeSize0);
    ASSERT_EQUAL(lattice.GetSize(1), latticeSize1);
    ASSERT_EQUAL(lattice.GetSize(2), latticeSize2);

    ASSERT_EQUAL(lattice.GetSize(), latticeSize0 * latticeSize1 * latticeSize2);
}

void CoreTools::MultiArrayTesting::GetIndexTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndex3Test);
}

void CoreTools::MultiArrayTesting::GetIndex0Test()
{
    const MultiArray<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple0 + latticeSize0 * (tuple1 + latticeSize1 * tuple2));
}

void CoreTools::MultiArrayTesting::GetIndex1Test()
{
    const MultiArray<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple2 + latticeSize2 * (tuple1 + latticeSize1 * tuple0));
}

void CoreTools::MultiArrayTesting::GetIndex2Test()
{
    const MultiArray<int, true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple0 + latticeSize0 * (tuple1 + latticeSize1 * tuple2));
}

void CoreTools::MultiArrayTesting::GetIndex3Test()
{
    const MultiArray<int, false> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto index = lattice.GetIndex(tuple0, tuple1, tuple2);

    ASSERT_EQUAL(index, tuple2 + latticeSize2 * (tuple1 + latticeSize1 * tuple0));
}

void CoreTools::MultiArrayTesting::GetIndexArrayTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetIndexArray3Test);
}

void CoreTools::MultiArrayTesting::GetIndexArray0Test()
{
    const MultiArray<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize3 + latticeSize0 * (latticeSize4 + latticeSize1 * latticeSize5));
}

void CoreTools::MultiArrayTesting::GetIndexArray1Test()
{
    const MultiArray<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize5 + latticeSize2 * (latticeSize4 + latticeSize1 * latticeSize3));
}

void CoreTools::MultiArrayTesting::GetIndexArray2Test()
{
    const MultiArray<int, true> lattice{ MultiArray<int, true>::SizeType{ latticeSize0, latticeSize1, latticeSize2 } };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize3 + latticeSize0 * (latticeSize4 + latticeSize1 * latticeSize5));
}

void CoreTools::MultiArrayTesting::GetIndexArray3Test()
{
    const MultiArray<int, false> lattice{ MultiArray<int, false>::SizeType{ latticeSize0, latticeSize1, latticeSize2 } };

    const auto index = lattice.GetIndex({ latticeSize3, latticeSize4, latticeSize5 });

    ASSERT_EQUAL(index, latticeSize5 + latticeSize2 * (latticeSize4 + latticeSize1 * latticeSize3));
}

void CoreTools::MultiArrayTesting::CoordinateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Coordinate3Test);
}

void CoreTools::MultiArrayTesting::Coordinate0Test()
{
    const MultiArray<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto coordinate = lattice.GetCoordinate<>(tuple3);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple3);
}

void CoreTools::MultiArrayTesting::Coordinate1Test()
{
    const MultiArray<int, false, latticeSize0, latticeSize1, latticeSize2> lattice{};

    const auto coordinate = lattice.GetCoordinate<>(tuple4);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple4);
}

void CoreTools::MultiArrayTesting::Coordinate2Test()
{
    const MultiArray<int, true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto coordinate = lattice.GetCoordinate<>(tuple3);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple3);
}

void CoreTools::MultiArrayTesting::Coordinate3Test()
{
    const MultiArray<int, false> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    const auto coordinate = lattice.GetCoordinate<>(tuple4);

    const auto index = lattice.GetIndex(coordinate);

    ASSERT_EQUAL(index, tuple4);
}

void CoreTools::MultiArrayTesting::OrderLToRTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToR0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToR1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderLToR2Test);
}

void CoreTools::MultiArrayTesting::OrderLToR0Test()
{
    MultiArrayType0 multiArray{ latticeSize0, latticeSize1, latticeSize5 };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToR0FillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToR0ValueTest, multiArray);
}

void CoreTools::MultiArrayTesting::OrderLToR0FillTest(MultiArrayType0& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
        multiArray[i] = i;
    }
}

void CoreTools::MultiArrayTesting::OrderLToR0ValueTest(MultiArrayType0& multiArray)
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

void CoreTools::MultiArrayTesting::OrderLToR1Test()
{
    MultiArrayType1 multiArray{};

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToR1InitTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_2(OrderLToR1ResultTest, multiArray, original);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] += increase;
    }

    ASSERT_NOT_THROW_EXCEPTION_2(OrderLToR1ResultTest, multiArray, original + increase);
}

void CoreTools::MultiArrayTesting::OrderLToR1InitTest(MultiArrayType1& multiArray)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(0); ++x0, ++i)
            {
                multiArray(x0, x1, x2) = i + original;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderLToR1ResultTest(MultiArrayType1& multiArray, float step)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(0); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray(x0, x1, x2), i + step, Mathematics::MathF::GetZeroTolerance());

                const std::array x{ x0, x1, x2 };

                ASSERT_APPROXIMATE(multiArray(x), i + step, Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderLToR2Test()
{
    MultiArrayType2 multiArray{ latticeSize6, latticeSize7, latticeSize8 };

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToR2InitTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_2(OrderLToR2ResultTest, multiArray, original);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] += increase;
    }

    ASSERT_NOT_THROW_EXCEPTION_2(OrderLToR2ResultTest, multiArray, original + increase);
}

void CoreTools::MultiArrayTesting::OrderLToR2InitTest(MultiArrayType2& multiArray)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(0); ++x0, ++i)
            {
                multiArray(x0, x1, x2) = i + original;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderLToR2ResultTest(MultiArrayType2& multiArray, float step)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(2); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(0); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray(x0, x1, x2), i + step, Mathematics::MathF::GetZeroTolerance());

                const std::vector x{ x0, x1, x2 };

                ASSERT_APPROXIMATE(multiArray(x), i + step, Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToLTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToL0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToL1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OrderRToL2Test);
}

void CoreTools::MultiArrayTesting::OrderRToL0Test()
{
    MultiArrayType3 multiArray{ latticeSize0, latticeSize1, latticeSize5 };

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToL0FillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToL0ValueTest, multiArray);
}

void CoreTools::MultiArrayTesting::OrderRToL0FillTest(MultiArrayType3& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
    }
}

void CoreTools::MultiArrayTesting::OrderRToL0ValueTest(MultiArrayType3& multiArray)
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

void CoreTools::MultiArrayTesting::OrderRToL1Test()
{
    MultiArrayType4 multiArray{};

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToL1InitTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_2(OrderRToL1ResultTest, multiArray, original);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] += increase;
    }

    ASSERT_NOT_THROW_EXCEPTION_2(OrderRToL1ResultTest, multiArray, original + increase);
}

void CoreTools::MultiArrayTesting::OrderRToL1InitTest(MultiArrayType4& multiArray)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(2); ++x0, ++i)
            {
                multiArray(x2, x1, x0) = i + original;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToL1ResultTest(MultiArrayType4& multiArray, float step)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(2); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray(x2, x1, x0), i + step, Mathematics::MathF::GetZeroTolerance());

                const std::array x{ x2, x1, x0 };

                ASSERT_APPROXIMATE(multiArray(x), i + step, Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToL2Test()
{
    MultiArrayType5 multiArray{ latticeSize6, latticeSize7, latticeSize8 };

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToL2InitTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_2(OrderRToL2ResultTest, multiArray, original);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        multiArray[i] += increase;
    }

    ASSERT_NOT_THROW_EXCEPTION_2(OrderRToL2ResultTest, multiArray, original + increase);
}

void CoreTools::MultiArrayTesting::OrderRToL2InitTest(MultiArrayType5& multiArray)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(2); ++x0, ++i)
            {
                multiArray(x2, x1, x0) = i + original;
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderRToL2ResultTest(MultiArrayType5& multiArray, float step)
{
    for (auto x2 = 0, i = 0; x2 < multiArray.GetSize(0); ++x2)
    {
        for (auto x1 = 0; x1 < multiArray.GetSize(1); ++x1)
        {
            for (auto x0 = 0; x0 < multiArray.GetSize(2); ++x0, ++i)
            {
                ASSERT_APPROXIMATE(multiArray(x2, x1, x0), i + step, Mathematics::MathF::GetZeroTolerance());

                const std::vector x{ x2, x1, x0 };

                ASSERT_APPROXIMATE(multiArray(x), i + step, Mathematics::MathF::GetZeroTolerance());
            }
        }
    }
}

void CoreTools::MultiArrayTesting::OrderLToRConstantTest()
{
    MultiArrayType6 multiArray{};

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRConstantFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderLToRConstantValueTest, multiArray);
}

void CoreTools::MultiArrayTesting::OrderLToRConstantFillTest(MultiArrayType6& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
    }
}

void CoreTools::MultiArrayTesting::OrderLToRConstantValueTest(MultiArrayType6& multiArray)
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

void CoreTools::MultiArrayTesting::OrderRToLConstantTest()
{
    MultiArrayType7 multiArray{};

    ASSERT_UNEQUAL_NULL_PTR(multiArray.GetData());

    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLConstantFillTest, multiArray);
    ASSERT_NOT_THROW_EXCEPTION_1(OrderRToLConstantValueTest, multiArray);
}

void CoreTools::MultiArrayTesting::OrderRToLConstantFillTest(MultiArrayType7& multiArray)
{
    multiArray.Fill(tuple5);

    for (auto i = 0; i < multiArray.GetSize(); ++i)
    {
        ASSERT_EQUAL(multiArray[i], tuple5);
    }
}

void CoreTools::MultiArrayTesting::OrderRToLConstantValueTest(MultiArrayType7& multiArray)
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

void CoreTools::MultiArrayTesting::CompareTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Compare0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Compare1Test);
}

void CoreTools::MultiArrayTesting::Compare0Test()
{
    const MultiArray<int, true, latticeSize0, latticeSize1, latticeSize2> lattice{};

    ASSERT_TRUE(lattice == lattice);
    ASSERT_FALSE(lattice != lattice);

    ASSERT_FALSE(lattice < lattice);
    ASSERT_FALSE(lattice > lattice);
    ASSERT_TRUE(lattice <= lattice);
    ASSERT_TRUE(lattice >= lattice);
}

void CoreTools::MultiArrayTesting::Compare1Test()
{
    const MultiArray<int, true> lattice{ latticeSize0, latticeSize1, latticeSize2 };

    ASSERT_TRUE(lattice == lattice);
    ASSERT_FALSE(lattice != lattice);

    ASSERT_FALSE(lattice < lattice);
    ASSERT_FALSE(lattice > lattice);
    ASSERT_TRUE(lattice <= lattice);
    ASSERT_TRUE(lattice >= lattice);
}
