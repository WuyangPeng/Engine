///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:08)

#include "LexicoArray2Testing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/LexicoArray2Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    LexicoArray2<true, double, 5, 4>::Container container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    LexicoArray2<true, double, 5, 4> lexicoArray2{ container };

    ASSERT_EQUAL(lexicoArray2.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray2.GetNumRows(), 5);

    auto index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_EQUAL(lexicoArray2(row, col), index);
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorLexicoArray2Test()
{
    LexicoArray2<false, double, 5, 4>::Container container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    LexicoArray2<false, double, 5, 4> lexicoArray2{ container };

    ASSERT_EQUAL(lexicoArray2.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray2.GetNumRows(), 5);

    auto index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_EQUAL(lexicoArray2(row, col), index);
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::RowMajorConstantLexicoArray2Test()
{
    LexicoArray2<true, double>::Container container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    LexicoArray2<true, double> lexicoArray2{ 5, 4, container };

    ASSERT_EQUAL(lexicoArray2.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray2.GetNumRows(), 5);

    auto index = 0;
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            ASSERT_EQUAL(lexicoArray2(row, col), index);
            ++index;
        }
    }
}

void CoreTools::LexicoArray2Testing::ColumnMajorConstantLexicoArray2Test()
{
    LexicoArray2<false, double>::Container container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    LexicoArray2<false, double> lexicoArray2{ 5, 4, container };

    ASSERT_EQUAL(lexicoArray2.GetNumColumns(), 4);
    ASSERT_EQUAL(lexicoArray2.GetNumRows(), 5);

    auto index = 0;
    for (auto col = 0; col < 4; ++col)
    {
        for (auto row = 0; row < 5; ++row)
        {
            ASSERT_EQUAL(lexicoArray2(row, col), index);
            ++index;
        }
    }
}
