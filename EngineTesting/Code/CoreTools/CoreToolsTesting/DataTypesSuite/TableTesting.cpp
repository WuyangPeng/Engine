/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 23:23)

#include "TableTesting.h"
#include "CoreTools/DataTypes/TableDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

#define COMPILE_ERROR_TEST

#undef COMPILE_ERROR_TEST

CoreTools::TableTesting::TableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TableTesting)

void CoreTools::TableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompileErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ForEachTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCoordinateTest);
}

void CoreTools::TableTesting::IntegerTest()
{
    IntegerTestingType table0{};

    auto table1 = IntegerRowTest(table0);

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerColumnTest, table0, table1);

    ASSERT_NOT_THROW_EXCEPTION_1(IntegerSquareBracketsTest, table1);
}

CoreTools::TableTesting::IntegerTestingType CoreTools::TableTesting::IntegerRowTest(IntegerTestingType& table)
{
    const IntegerTuple2 rowTuple0{ 1, 2 };
    const IntegerTuple2 rowTuple1{ 3, 4 };
    const IntegerTuple2 rowTuple2{ 5, 6 };

    table.SetRow(0, rowTuple0);
    table.SetRow(1, rowTuple1);
    table.SetRow(2, rowTuple2);

    const Table result{ table };

    DoIntegerRowTest(table, rowTuple0, rowTuple1, rowTuple2);
    DoIntegerRowTest(result, rowTuple0, rowTuple1, rowTuple2);

    return result;
}

void CoreTools::TableTesting::DoIntegerRowTest(const IntegerTestingType& table, const IntegerTuple2& rowTuple0, const IntegerTuple2& rowTuple1, const IntegerTuple2& rowTuple2)
{
    ASSERT_EQUAL(table(0, 0), 1);
    ASSERT_EQUAL(table(0, 1), 2);
    ASSERT_EQUAL(table(1, 0), 3);
    ASSERT_EQUAL(table(1, 1), 4);
    ASSERT_EQUAL(table(2, 0), 5);
    ASSERT_EQUAL(table(2, 1), 6);
    ASSERT_EQUAL(table.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table.GetRow(1), rowTuple1);
    ASSERT_EQUAL(table.GetRow(2), rowTuple2);
}

void CoreTools::TableTesting::IntegerColumnTest(IntegerTestingType& lhs, IntegerTestingType& rhs)
{
    const IntegerTuple3 columnTuple0{ 7, 8, 9 };
    const IntegerTuple3 columnTuple1{ 10, 11, 12 };

    rhs.SetColumn(0, columnTuple0);
    rhs.SetColumn(1, columnTuple1);

    lhs = rhs;

    ASSERT_NOT_THROW_EXCEPTION_3(DoIntegerColumnTest, lhs, columnTuple0, columnTuple1);
    ASSERT_NOT_THROW_EXCEPTION_3(DoIntegerColumnTest, rhs, columnTuple0, columnTuple1);
}

void CoreTools::TableTesting::DoIntegerColumnTest(const IntegerTestingType& table, const IntegerTuple3& columnTuple0, const IntegerTuple3& columnTuple1)
{
    ASSERT_EQUAL(table(0, 0), 7);
    ASSERT_EQUAL(table(0, 1), 10);
    ASSERT_EQUAL(table(1, 0), 8);
    ASSERT_EQUAL(table(1, 1), 11);
    ASSERT_EQUAL(table(2, 0), 9);
    ASSERT_EQUAL(table(2, 1), 12);
    ASSERT_EQUAL(table.GetColumn(0), columnTuple0);
    ASSERT_EQUAL(table.GetColumn(1), columnTuple1);
}

void CoreTools::TableTesting::IntegerSquareBracketsTest(const IntegerTestingType& table)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(table[0]), 7);
    ASSERT_EQUAL(*(table[0] + 1), 10);
    ASSERT_EQUAL(*(table[1]), 8);
    ASSERT_EQUAL(*(table[1] + 1), 11);
    ASSERT_EQUAL(*(table[2]), 9);
    ASSERT_EQUAL(*(table[2] + 1), 12);

#include SYSTEM_WARNING_POP
}

void CoreTools::TableTesting::StringTest()
{
    StringTestingType table0{};

    auto table1 = StringRowTest(table0);

    ASSERT_NOT_THROW_EXCEPTION_2(StringColumnTest, table0, table1);

    ASSERT_NOT_THROW_EXCEPTION_1(StringSquareBracketsTest, table1);
}

CoreTools::TableTesting::StringTestingType CoreTools::TableTesting::StringRowTest(StringTestingType& table)
{
    const StringTuple rowTuple0("test0", "test1");
    const StringTuple rowTuple1("test2", "test3");

    table.SetRow(0, rowTuple0);
    table.SetRow(1, rowTuple1);

    Table result{ table };

    ASSERT_NOT_THROW_EXCEPTION_3(DoStringRowTest, table, rowTuple0, rowTuple1);
    ASSERT_NOT_THROW_EXCEPTION_3(DoStringRowTest, result, rowTuple0, rowTuple1);

    return result;
}

void CoreTools::TableTesting::DoStringRowTest(const StringTestingType& table, const StringTuple& rowTuple0, const StringTuple& rowTuple1)
{
    ASSERT_EQUAL(table(0, 0), "test0");
    ASSERT_EQUAL(table(0, 1), "test1");
    ASSERT_EQUAL(table(1, 0), "test2");
    ASSERT_EQUAL(table(1, 1), "test3");
    ASSERT_EQUAL(table.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table.GetRow(1), rowTuple1);
}

void CoreTools::TableTesting::StringColumnTest(StringTestingType& lhs, StringTestingType& rhs)
{
    const StringTuple columnTuple0{ "test4", "test5" };
    const StringTuple columnTuple1{ "test6", "test7" };

    rhs.SetColumn(0, columnTuple0);
    rhs.SetColumn(1, columnTuple1);

    lhs = rhs;

    ASSERT_NOT_THROW_EXCEPTION_3(DoStringColumnTest, lhs, columnTuple0, columnTuple1);
    ASSERT_NOT_THROW_EXCEPTION_3(DoStringColumnTest, rhs, columnTuple0, columnTuple1);
}

void CoreTools::TableTesting::DoStringColumnTest(const StringTestingType& table, const StringTuple& columnTuple0, const StringTuple& columnTuple1)
{
    ASSERT_EQUAL(table(0, 0), "test4");
    ASSERT_EQUAL(table(0, 1), "test6");
    ASSERT_EQUAL(table(1, 0), "test5");
    ASSERT_EQUAL(table(1, 1), "test7");
    ASSERT_EQUAL(table.GetColumn(0), columnTuple0);
    ASSERT_EQUAL(table.GetColumn(1), columnTuple1);
}

void CoreTools::TableTesting::StringSquareBracketsTest(const StringTestingType& table)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(table[0]), "test4");
    ASSERT_EQUAL(*(table[0] + 1), "test6");
    ASSERT_EQUAL(*(table[1]), "test5");
    ASSERT_EQUAL(*(table[1] + 1), "test7");

#include SYSTEM_WARNING_POP
}

void CoreTools::TableTesting::OperatorTest()
{
    auto table0 = CreateTestingType2();
    const auto table1 = CreateTestingType2();

    ASSERT_TRUE(table0 == table1);
    ASSERT_FALSE(table0 != table1);
    ASSERT_FALSE(table1 < table0);
    ASSERT_TRUE(table1 <= table0);
    ASSERT_FALSE(table0 > table1);
    ASSERT_TRUE(table0 >= table1);

    table0(0, 0) = 1;

    ASSERT_FALSE(table0 == table1);
    ASSERT_TRUE(table0 != table1);
    ASSERT_TRUE(table1 < table0);
    ASSERT_TRUE(table1 <= table0);
    ASSERT_TRUE(table0 > table1);
    ASSERT_TRUE(table0 >= table1);
}

CoreTools::TableTesting::TestingType2 CoreTools::TableTesting::CreateTestingType2()
{
    TestingType2 table{};

    auto index = 0;
    for (auto row = 0; row < TestingType2::rowsNumber; ++row)
    {
        for (auto column = 0; column < TestingType2::columnsNumber; ++column)
        {
            table(row, column) = index;
            ++index;
        }
    }

    return table;
}

void CoreTools::TableTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor4Test);
}

void CoreTools::TableTesting::Constructor2Test()
{
    TestingType2 table{ 1, 2, 3, 4 };

    auto index = 1;
    for (auto row = 0; row < TestingType2::rowsNumber; ++row)
    {
        for (auto column = 0; column < TestingType2::columnsNumber; ++column)
        {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)

            ASSERT_EQUAL(table[row][column], index);

#include SYSTEM_WARNING_POP

            ++index;
        }
    }
}

void CoreTools::TableTesting::Constructor3Test()
{
    TestingType3 table{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto index = 1;
    for (auto row = 0; row < TestingType3::rowsNumber; ++row)
    {
        for (auto column = 0; column < TestingType3::columnsNumber; ++column)
        {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)

            ASSERT_EQUAL(table[row][column], index);

#include SYSTEM_WARNING_POP

            ++index;
        }
    }
}

void CoreTools::TableTesting::Constructor4Test()
{
    TestingType4 table{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    auto index = 1;
    for (auto row = 0; row < TestingType4::rowsNumber; ++row)
    {
        for (auto column = 0; column < TestingType4::columnsNumber; ++column)
        {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)

            ASSERT_EQUAL(table[row][column], index);

#include SYSTEM_WARNING_POP

            ++index;
        }
    }
}

void CoreTools::TableTesting::CompileErrorTest() noexcept
{
#ifdef COMPILE_ERROR_TEST

    /// 以下代码无法通过编译
    TestingType2 table1{ 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    TestingType3 table2{ 5, 6, 7, 8 };
    TestingType4 table3{ 5, 6, 7, 8 };

#endif  // COMPILE_ERROR_TEST
}

void CoreTools::TableTesting::ForEachTest()
{
    const TestingType2 tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto element : tuple)
    {
        ASSERT_EQUAL(element, index);

        ++index;
    }
}

void CoreTools::TableTesting::GetCoordinateTest()
{
    const TestingType2 tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto element : tuple.GetCoordinate())
    {
        ASSERT_EQUAL(element, index);

        ++index;
    }
}
