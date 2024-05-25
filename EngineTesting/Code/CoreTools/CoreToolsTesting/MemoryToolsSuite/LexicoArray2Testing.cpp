/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/16 22:07)

#include "LexicoArray2Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/LexicoArray2Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <numeric>

CoreTools::LexicoArray2Testing::LexicoArray2Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LexicoArray2Testing)

void CoreTools::LexicoArray2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LexicoArray2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RowMajorLexicoArray2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ColumnMajorLexicoArray2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(RowMajorConstantLexicoArray2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ColumnMajorConstantLexicoArray2Test);
}

void CoreTools::LexicoArray2Testing::RowMajorLexicoArray2Test()
{
    DoubleContainer container0(containerSize);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2Type0 lexicoArray0{ container0.begin(), container0.end() };

    ASSERT_NOT_THROW_EXCEPTION_1(RowMajorLexicoArray2Result0Test, lexicoArray0);

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2Type1 lexicoArray1{ { container1.cbegin(), container1.cend() } };

    ASSERT_NOT_THROW_EXCEPTION_2(RowMajorLexicoArray2Result1Test, lexicoArray0, lexicoArray1);
}

void CoreTools::LexicoArray2Testing::RowMajorLexicoArray2Result0Test(LexicoArray2Type0& lexicoArray)
{
    ASSERT_EQUAL(lexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(lexicoArray.GetNumRows(), numRows);

    auto index = 0;
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            ASSERT_APPROXIMATE(lexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::RowMajorLexicoArray2Result1Test(LexicoArray2Type0& lhsLexicoArray, LexicoArray2Type1& rhsLexicoArray)
{
    ASSERT_EQUAL(rhsLexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(rhsLexicoArray.GetNumRows(), numRows);

    lhsLexicoArray.FillZero();

    auto index = 0;
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            ASSERT_APPROXIMATE(lhsLexicoArray(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(rhsLexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorLexicoArray2Test()
{
    DoubleContainer container0(containerSize);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2Type2 lexicoArray0{ { container0.begin(), container0.end() } };

    ASSERT_NOT_THROW_EXCEPTION_1(ColumnMajorLexicoArray2Result0Test, lexicoArray0);

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2Type3 lexicoArray1{ container1.cbegin(), container1.cend() };

    ASSERT_NOT_THROW_EXCEPTION_2(ColumnMajorLexicoArray2Result1Test, lexicoArray0, lexicoArray1);
}

void CoreTools::LexicoArray2Testing::ColumnMajorLexicoArray2Result0Test(LexicoArray2Type2& lexicoArray)
{
    ASSERT_EQUAL(lexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(lexicoArray.GetNumRows(), numRows);

    auto index = 0;
    for (auto col = 0; col < numColumns; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            ASSERT_APPROXIMATE(lexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorLexicoArray2Result1Test(LexicoArray2Type2& lhsLexicoArray, LexicoArray2Type3& rhsLexicoArray)
{
    ASSERT_EQUAL(rhsLexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(rhsLexicoArray.GetNumRows(), numRows);

    lhsLexicoArray.FillZero();

    auto index = 0;
    for (auto col = 0; col < numColumns; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            ASSERT_APPROXIMATE(lhsLexicoArray(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(rhsLexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::RowMajorConstantLexicoArray2Test()
{
    DoubleContainer container0(containerSize);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2Type4 lexicoArray0{ numRows, numColumns, { container0.begin(), container0.end() } };

    ASSERT_NOT_THROW_EXCEPTION_1(RowMajorConstantLexicoArray2Result0Test, lexicoArray0);

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2Type5 lexicoArray1{ numRows, numColumns, container1.cbegin(), container1.cend() };

    ASSERT_NOT_THROW_EXCEPTION_2(RowMajorConstantLexicoArray2Result1Test, lexicoArray0, lexicoArray1);
}

void CoreTools::LexicoArray2Testing::RowMajorConstantLexicoArray2Result0Test(LexicoArray2Type4& lexicoArray)
{
    ASSERT_EQUAL(lexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(lexicoArray.GetNumRows(), numRows);

    auto index = 0;
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            ASSERT_EQUAL(lexicoArray(row, col), index);
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::RowMajorConstantLexicoArray2Result1Test(LexicoArray2Type4& lhsLexicoArray, LexicoArray2Type5& rhsLexicoArray)
{
    ASSERT_EQUAL(rhsLexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(rhsLexicoArray.GetNumRows(), numRows);

    lhsLexicoArray.FillZero();

    auto index = 0;
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            ASSERT_APPROXIMATE(lhsLexicoArray(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(rhsLexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorConstantLexicoArray2Test()
{
    DoubleContainer container0(containerSize);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2Type6 lexicoArray0{ numRows, numColumns, { container0.begin(), container0.end() } };

    ASSERT_NOT_THROW_EXCEPTION_1(ColumnMajorConstantLexicoArray2Result0Test, lexicoArray0);

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2Type7 lexicoArray1{ numRows, numColumns, container1.cbegin(), container1.cend() };

    ASSERT_NOT_THROW_EXCEPTION_2(ColumnMajorConstantLexicoArray2Result1Test, lexicoArray0, lexicoArray1);
}

void CoreTools::LexicoArray2Testing::ColumnMajorConstantLexicoArray2Result0Test(LexicoArray2Type6& lexicoArray)
{
    ASSERT_EQUAL(lexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(lexicoArray.GetNumRows(), numRows);

    auto index = 0;
    for (auto col = 0; col < numColumns; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            ASSERT_EQUAL(lexicoArray(row, col), index);
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorConstantLexicoArray2Result1Test(LexicoArray2Type6& lhsLexicoArray, LexicoArray2Type7& rhsLexicoArray)
{
    ASSERT_EQUAL(rhsLexicoArray.GetNumColumns(), numColumns);
    ASSERT_EQUAL(rhsLexicoArray.GetNumRows(), numRows);

    lhsLexicoArray.FillZero();

    auto index = 0;
    for (auto col = 0; col < numColumns; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            ASSERT_APPROXIMATE(lhsLexicoArray(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(rhsLexicoArray(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}