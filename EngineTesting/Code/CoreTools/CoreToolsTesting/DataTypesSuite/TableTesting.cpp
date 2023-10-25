///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:30)

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
    Table<3, 2, int> table0{};

    const Tuple<2, int> rowTuple0(1, 22);
    const Tuple<2, int> rowTuple1(12, 221);
    const Tuple<2, int> rowTuple2(134, 2233);

    table0.SetRow(0, rowTuple0);
    table0.SetRow(1, rowTuple1);
    table0.SetRow(2, rowTuple2);

    Table table1{ table0 };

    ASSERT_EQUAL(table0(0, 0), 1);
    ASSERT_EQUAL(table0(0, 1), 22);
    ASSERT_EQUAL(table0(1, 0), 12);
    ASSERT_EQUAL(table0(1, 1), 221);
    ASSERT_EQUAL(table0(2, 0), 134);
    ASSERT_EQUAL(table0(2, 1), 2233);
    ASSERT_EQUAL(table0.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table0.GetRow(1), rowTuple1);
    ASSERT_EQUAL(table0.GetRow(2), rowTuple2);

    ASSERT_EQUAL(table1(0, 0), 1);
    ASSERT_EQUAL(table1(0, 1), 22);
    ASSERT_EQUAL(table1(1, 0), 12);
    ASSERT_EQUAL(table1(1, 1), 221);
    ASSERT_EQUAL(table1(2, 0), 134);
    ASSERT_EQUAL(table1(2, 1), 2233);
    ASSERT_EQUAL(table1.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table1.GetRow(1), rowTuple1);
    ASSERT_EQUAL(table1.GetRow(2), rowTuple2);

    const Tuple<3, int> columnTuple0{ 1221, 2212, 221232 };
    const Tuple<3, int> columnTuple1{ 123, 22131, 221312 };

    table1.SetColumn(0, columnTuple0);
    table1.SetColumn(1, columnTuple1);

    table0 = table1;

    ASSERT_EQUAL(table0(0, 0), 1221);
    ASSERT_EQUAL(table0(0, 1), 123);
    ASSERT_EQUAL(table0(1, 0), 2212);
    ASSERT_EQUAL(table0(1, 1), 22131);
    ASSERT_EQUAL(table0(2, 0), 221232);
    ASSERT_EQUAL(table0(2, 1), 221312);
    ASSERT_EQUAL(table0.GetColumn(0), columnTuple0);
    ASSERT_EQUAL(table0.GetColumn(1), columnTuple1);

    ASSERT_EQUAL(table1(0, 0), 1221);
    ASSERT_EQUAL(table1(0, 1), 123);
    ASSERT_EQUAL(table1(1, 0), 2212);
    ASSERT_EQUAL(table1(1, 1), 22131);
    ASSERT_EQUAL(table1(2, 0), 221232);
    ASSERT_EQUAL(table1(2, 1), 221312);
    ASSERT_EQUAL(table1.GetColumn(0), columnTuple0);
    ASSERT_EQUAL(table1.GetColumn(1), columnTuple1);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(table1[0]), 1221);
    ASSERT_EQUAL(*(table1[0] + 1), 123);
    ASSERT_EQUAL(*(table1[1]), 2212);
    ASSERT_EQUAL(*(table1[1] + 1), 22131);
    ASSERT_EQUAL(*(table1[2]), 221232);
    ASSERT_EQUAL(*(table1[2] + 1), 221312);

#include SYSTEM_WARNING_POP
}

void CoreTools::TableTesting::StringTest()
{
    Table<2, 2, std::string> table0{};

    const Tuple<2, std::string> rowTuple0("first0", "first1");
    const Tuple<2, std::string> rowTuple1("second0", "second1");

    table0.SetRow(0, rowTuple0);
    table0.SetRow(1, rowTuple1);

    Table table1{ table0 };

    ASSERT_EQUAL(table0(0, 0), "first0");
    ASSERT_EQUAL(table0(0, 1), "first1");
    ASSERT_EQUAL(table0(1, 0), "second0");
    ASSERT_EQUAL(table0(1, 1), "second1");
    ASSERT_EQUAL(table0.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table0.GetRow(1), rowTuple1);

    ASSERT_EQUAL(table1(0, 0), "first0");
    ASSERT_EQUAL(table1(0, 1), "first1");
    ASSERT_EQUAL(table1(1, 0), "second0");
    ASSERT_EQUAL(table1(1, 1), "second1");
    ASSERT_EQUAL(table1.GetRow(0), rowTuple0);
    ASSERT_EQUAL(table1.GetRow(1), rowTuple1);

    const Tuple<2, std::string> columnTuple1{ "second1", "second0" };
    const Tuple<2, std::string> columnTuple2{ "first1", "first0" };

    table1.SetColumn(0, columnTuple1);
    table1.SetColumn(1, columnTuple2);

    table0 = table1;

    ASSERT_EQUAL(table0(0, 0), "second1");
    ASSERT_EQUAL(table0(0, 1), "first1");
    ASSERT_EQUAL(table0(1, 0), "second0");
    ASSERT_EQUAL(table0(1, 1), "first0");
    ASSERT_EQUAL(table0.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(table0.GetColumn(1), columnTuple2);

    ASSERT_EQUAL(table1(0, 0), "second1");
    ASSERT_EQUAL(table1(0, 1), "first1");
    ASSERT_EQUAL(table1(1, 0), "second0");
    ASSERT_EQUAL(table1(1, 1), "first0");
    ASSERT_EQUAL(table1.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(table1.GetColumn(1), columnTuple2);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(table1[0]), "second1");
    ASSERT_EQUAL(*(table1[0] + 1), "first1");
    ASSERT_EQUAL(*(table1[1]), "second0");
    ASSERT_EQUAL(*(table1[1] + 1), "first0");

#include SYSTEM_WARNING_POP
}

void CoreTools::TableTesting::OperatorTest()
{
    Table<2, 2, int> table0{};
    Table<2, 2, int> table1{};

    table0(0, 0) = 0;
    table0(0, 1) = 0;
    table0(1, 0) = 0;
    table0(1, 1) = 0;
    table1(0, 0) = 0;
    table1(0, 1) = 0;
    table1(1, 0) = 0;
    table1(1, 1) = 0;

    ASSERT_TRUE(table0 == table1);
    ASSERT_FALSE(table0 != table1);

    table0(0, 0) = 1;

    ASSERT_TRUE(table1 < table0);
    ASSERT_TRUE(table1 <= table0);
    ASSERT_TRUE(table0 > table1);
    ASSERT_TRUE(table0 >= table1);
}

void CoreTools::TableTesting::ConstructorTest()
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    Table<2, 2, int> table0{ 1, 2, 3, 4 };

    ASSERT_EQUAL(table0[0][0], 1);
    ASSERT_EQUAL(table0[0][1], 2);
    ASSERT_EQUAL(table0[1][0], 3);
    ASSERT_EQUAL(table0[1][1], 4);

    Table<3, 3, int> table1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_EQUAL(table1[0][0], 1);
    ASSERT_EQUAL(table1[0][1], 2);
    ASSERT_EQUAL(table1[0][2], 3);
    ASSERT_EQUAL(table1[1][0], 4);
    ASSERT_EQUAL(table1[1][1], 5);
    ASSERT_EQUAL(table1[1][2], 6);
    ASSERT_EQUAL(table1[2][0], 7);
    ASSERT_EQUAL(table1[2][1], 8);
    ASSERT_EQUAL(table1[2][2], 9);

    Table<4, 4, int> table2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    ASSERT_EQUAL(table2[0][0], 1);
    ASSERT_EQUAL(table2[0][1], 2);
    ASSERT_EQUAL(table2[0][2], 3);
    ASSERT_EQUAL(table2[0][3], 4);
    ASSERT_EQUAL(table2[1][0], 5);
    ASSERT_EQUAL(table2[1][1], 6);
    ASSERT_EQUAL(table2[1][2], 7);
    ASSERT_EQUAL(table2[1][3], 8);
    ASSERT_EQUAL(table2[2][0], 9);
    ASSERT_EQUAL(table2[2][1], 10);
    ASSERT_EQUAL(table2[2][2], 11);
    ASSERT_EQUAL(table2[2][3], 12);
    ASSERT_EQUAL(table2[3][0], 13);
    ASSERT_EQUAL(table2[3][1], 14);
    ASSERT_EQUAL(table2[3][2], 15);
    ASSERT_EQUAL(table2[3][3], 16);

#include SYSTEM_WARNING_POP
}

void CoreTools::TableTesting::CompileErrorTest() noexcept
{
#ifdef COMPILE_ERROR_TEST

    // 以下代码无法通过编译
    Table<2, 2, int> table1{ 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Table<3, 3, int> table2{ 5, 6, 7, 8 };
    Table<4, 4, int> table3{ 5, 6, 7, 8 };

#endif  // COMPILE_ERROR_TEST
}

void CoreTools::TableTesting::ForEachTest()
{
    const Table<2, 2, int> tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto value : tuple)
    {
        ASSERT_EQUAL(value, index);

        ++index;
    }
}

void CoreTools::TableTesting::GetCoordinateTest()
{
    const Table<2, 2, int> tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto value : tuple.GetCoordinate())
    {
        ASSERT_EQUAL(value, index);

        ++index;
    }
}
