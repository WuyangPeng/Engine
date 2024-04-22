/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:06)

#include "LexicoArray2Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/LexicoArray2Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <Mathematics/Base/Math.h>

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
    DoubleContainer container0(20);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2<true, DoubleContainerIter, 5, 4> lexicoArray0{ container0.begin(), container0.end() };

    ASSERT_EQUAL(lexicoArray0.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray0.GetNumRows(), 5);

    auto index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2<true, DoubleContainerConstIter, 5, 4> lexicoArray1{ { container1.cbegin(), container1.cend() } };

    ASSERT_EQUAL(lexicoArray1.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray1.GetNumRows(), 5);

    lexicoArray0.FillZero();

    index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(lexicoArray1(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorLexicoArray2Test()
{
    DoubleContainer container0(20);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2<false, DoubleContainerIter, 5, 4> lexicoArray0{ { container0.begin(), container0.end() } };

    ASSERT_EQUAL(lexicoArray0.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray0.GetNumRows(), 5);

    auto index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2<false, DoubleContainerConstIter, 5, 4> lexicoArray1{ container1.cbegin(), container1.cend() };

    ASSERT_EQUAL(lexicoArray1.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray1.GetNumRows(), 5);

    lexicoArray0.FillZero();

    index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(lexicoArray1(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::RowMajorConstantLexicoArray2Test()
{
    DoubleContainer container0(20);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2<true, DoubleContainerIter> lexicoArray0{ 5, 4, { container0.begin(), container0.end() } };

    ASSERT_EQUAL(lexicoArray0.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray0.GetNumRows(), 5);

    auto index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_EQUAL(lexicoArray0(row, col), index);
            ++index;
        }
    }

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2<true, DoubleContainerConstIter> lexicoArray1{ 5, 4, container1.cbegin(), container1.cend() };

    ASSERT_EQUAL(lexicoArray1.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray1.GetNumRows(), 5);

    lexicoArray0.FillZero();

    index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(lexicoArray1(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorConstantLexicoArray2Test()
{
    DoubleContainer container0(20);
    std::iota(container0.begin(), container0.end(), 0.0);

    LexicoArray2<false, DoubleContainerIter> lexicoArray0{ 5, 4, { container0.begin(), container0.end() } };

    ASSERT_EQUAL(lexicoArray0.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray0.GetNumRows(), 5);

    auto index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_EQUAL(lexicoArray0(row, col), index);
            ++index;
        }
    }

    const auto container1 = lexicoArray0.GetContainer<DoubleContainer>();

    LexicoArray2<false, DoubleContainerConstIter> lexicoArray1{ 5, 4, container1.cbegin(), container1.cend() };

    ASSERT_EQUAL(lexicoArray1.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray1.GetNumRows(), 5);

    lexicoArray0.FillZero();

    index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_APPROXIMATE(lexicoArray0(row, col), 0.0, Mathematics::MathD::GetZeroTolerance());
            ASSERT_APPROXIMATE(lexicoArray1(row, col), index, Mathematics::MathD::GetZeroTolerance());
            ++index;
        }
    }
}
