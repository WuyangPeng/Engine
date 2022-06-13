///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:55)

#include "TableTesting.h"
#include "CoreTools/DataTypes/TableDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <string>

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TableTesting)

void CoreTools::TableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompileErrorTest);
}

void CoreTools::TableTesting::IntegerTest()
{
    Table<3, 2, int> integerTable1{};

    const Tuple<2, int> rowTuple1(1, 22);
    const Tuple<2, int> rowTuple2(12, 221);
    const Tuple<2, int> rowTuple3(134, 2233);

    integerTable1.SetRow(0, rowTuple1);
    integerTable1.SetRow(1, rowTuple2);
    integerTable1.SetRow(2, rowTuple3);

    Table<3, 2, int> integerTable2{ integerTable1 };

    ASSERT_EQUAL(integerTable1(0, 0), 1);
    ASSERT_EQUAL(integerTable1(0, 1), 22);
    ASSERT_EQUAL(integerTable1(1, 0), 12);
    ASSERT_EQUAL(integerTable1(1, 1), 221);
    ASSERT_EQUAL(integerTable1(2, 0), 134);
    ASSERT_EQUAL(integerTable1(2, 1), 2233);
    ASSERT_EQUAL(integerTable1.GetRow(0), rowTuple1);
    ASSERT_EQUAL(integerTable1.GetRow(1), rowTuple2);
    ASSERT_EQUAL(integerTable1.GetRow(2), rowTuple3);

    ASSERT_EQUAL(integerTable2(0, 0), 1);
    ASSERT_EQUAL(integerTable2(0, 1), 22);
    ASSERT_EQUAL(integerTable2(1, 0), 12);
    ASSERT_EQUAL(integerTable2(1, 1), 221);
    ASSERT_EQUAL(integerTable2(2, 0), 134);
    ASSERT_EQUAL(integerTable2(2, 1), 2233);
    ASSERT_EQUAL(integerTable2.GetRow(0), rowTuple1);
    ASSERT_EQUAL(integerTable2.GetRow(1), rowTuple2);
    ASSERT_EQUAL(integerTable2.GetRow(2), rowTuple3);

    const Tuple<3, int> columnTuple1{ 1221, 2212, 221232 };
    const Tuple<3, int> columnTuple2{ 123, 22131, 221312 };

    integerTable2.SetColumn(0, columnTuple1);
    integerTable2.SetColumn(1, columnTuple2);

    integerTable1 = integerTable2;

    ASSERT_EQUAL(integerTable1(0, 0), 1221);
    ASSERT_EQUAL(integerTable1(0, 1), 123);
    ASSERT_EQUAL(integerTable1(1, 0), 2212);
    ASSERT_EQUAL(integerTable1(1, 1), 22131);
    ASSERT_EQUAL(integerTable1(2, 0), 221232);
    ASSERT_EQUAL(integerTable1(2, 1), 221312);
    ASSERT_EQUAL(integerTable1.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(integerTable1.GetColumn(1), columnTuple2);

    ASSERT_EQUAL(integerTable2(0, 0), 1221);
    ASSERT_EQUAL(integerTable2(0, 1), 123);
    ASSERT_EQUAL(integerTable2(1, 0), 2212);
    ASSERT_EQUAL(integerTable2(1, 1), 22131);
    ASSERT_EQUAL(integerTable2(2, 0), 221232);
    ASSERT_EQUAL(integerTable2(2, 1), 221312);
    ASSERT_EQUAL(integerTable2.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(integerTable2.GetColumn(1), columnTuple2);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(integerTable2[0]), 1221);
    ASSERT_EQUAL(*(integerTable2[0] + 1), 123);
    ASSERT_EQUAL(*(integerTable2[1]), 2212);
    ASSERT_EQUAL(*(integerTable2[1] + 1), 22131);
    ASSERT_EQUAL(*(integerTable2[2]), 221232);
    ASSERT_EQUAL(*(integerTable2[2] + 1), 221312);

#include STSTEM_WARNING_POP
}

void CoreTools::TableTesting::StringTest()
{
    Table<2, 2, string> stringTable1{};

    Tuple<2, string> rowTuple1("first0", "first1");
    Tuple<2, string> rowTuple2("second0", "second1");

    stringTable1.SetRow(0, rowTuple1);
    stringTable1.SetRow(1, rowTuple2);

    Table<2, 2, string> stringTable2{ stringTable1 };

    ASSERT_EQUAL(stringTable1(0, 0), "first0");
    ASSERT_EQUAL(stringTable1(0, 1), "first1");
    ASSERT_EQUAL(stringTable1(1, 0), "second0");
    ASSERT_EQUAL(stringTable1(1, 1), "second1");
    ASSERT_EQUAL(stringTable1.GetRow(0), rowTuple1);
    ASSERT_EQUAL(stringTable1.GetRow(1), rowTuple2);

    ASSERT_EQUAL(stringTable2(0, 0), "first0");
    ASSERT_EQUAL(stringTable2(0, 1), "first1");
    ASSERT_EQUAL(stringTable2(1, 0), "second0");
    ASSERT_EQUAL(stringTable2(1, 1), "second1");
    ASSERT_EQUAL(stringTable2.GetRow(0), rowTuple1);
    ASSERT_EQUAL(stringTable2.GetRow(1), rowTuple2);

    Tuple<2, string> columnTuple1{ "second1", "second0" };
    Tuple<2, string> columnTuple2{ "first1", "first0" };

    stringTable2.SetColumn(0, columnTuple1);
    stringTable2.SetColumn(1, columnTuple2);

    stringTable1 = stringTable2;

    ASSERT_EQUAL(stringTable1(0, 0), "second1");
    ASSERT_EQUAL(stringTable1(0, 1), "first1");
    ASSERT_EQUAL(stringTable1(1, 0), "second0");
    ASSERT_EQUAL(stringTable1(1, 1), "first0");
    ASSERT_EQUAL(stringTable1.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(stringTable1.GetColumn(1), columnTuple2);

    ASSERT_EQUAL(stringTable2(0, 0), "second1");
    ASSERT_EQUAL(stringTable2(0, 1), "first1");
    ASSERT_EQUAL(stringTable2(1, 0), "second0");
    ASSERT_EQUAL(stringTable2(1, 1), "first0");
    ASSERT_EQUAL(stringTable2.GetColumn(0), columnTuple1);
    ASSERT_EQUAL(stringTable2.GetColumn(1), columnTuple2);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(*(stringTable2[0]), "second1");
    ASSERT_EQUAL(*(stringTable2[0] + 1), "first1");
    ASSERT_EQUAL(*(stringTable2[1]), "second0");
    ASSERT_EQUAL(*(stringTable2[1] + 1), "first0");

#include STSTEM_WARNING_POP
}

void CoreTools::TableTesting::OperatorTest()
{
    Table<2, 2, int> integerTable1{};
    Table<2, 2, int> integerTable2{};

    integerTable1(0, 0) = 0;
    integerTable1(0, 1) = 0;
    integerTable1(1, 0) = 0;
    integerTable1(1, 1) = 0;
    integerTable2(0, 0) = 0;
    integerTable2(0, 1) = 0;
    integerTable2(1, 0) = 0;
    integerTable2(1, 1) = 0;

    ASSERT_TRUE(integerTable1 == integerTable2);
    ASSERT_FALSE(integerTable1 != integerTable2);

    integerTable1(0, 0) = 1;

    ASSERT_TRUE(integerTable2 < integerTable1);
    ASSERT_TRUE(integerTable2 <= integerTable1);
    ASSERT_TRUE(integerTable1 > integerTable2);
    ASSERT_TRUE(integerTable1 >= integerTable2);
}

void CoreTools::TableTesting::ConstructorTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    Table<2, 2, int> integerTable1{ 1, 2, 3, 4 };

    ASSERT_EQUAL(integerTable1[0][0], 1);
    ASSERT_EQUAL(integerTable1[0][1], 2);
    ASSERT_EQUAL(integerTable1[1][0], 3);
    ASSERT_EQUAL(integerTable1[1][1], 4);

    Table<3, 3, int> integerTable2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_EQUAL(integerTable2[0][0], 1);
    ASSERT_EQUAL(integerTable2[0][1], 2);
    ASSERT_EQUAL(integerTable2[0][2], 3);
    ASSERT_EQUAL(integerTable2[1][0], 4);
    ASSERT_EQUAL(integerTable2[1][1], 5);
    ASSERT_EQUAL(integerTable2[1][2], 6);
    ASSERT_EQUAL(integerTable2[2][0], 7);
    ASSERT_EQUAL(integerTable2[2][1], 8);
    ASSERT_EQUAL(integerTable2[2][2], 9);

    Table<4, 4, int> integerTable3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    ASSERT_EQUAL(integerTable3[0][0], 1);
    ASSERT_EQUAL(integerTable3[0][1], 2);
    ASSERT_EQUAL(integerTable3[0][2], 3);
    ASSERT_EQUAL(integerTable3[0][3], 4);
    ASSERT_EQUAL(integerTable3[1][0], 5);
    ASSERT_EQUAL(integerTable3[1][1], 6);
    ASSERT_EQUAL(integerTable3[1][2], 7);
    ASSERT_EQUAL(integerTable3[1][3], 8);
    ASSERT_EQUAL(integerTable3[2][0], 9);
    ASSERT_EQUAL(integerTable3[2][1], 10);
    ASSERT_EQUAL(integerTable3[2][2], 11);
    ASSERT_EQUAL(integerTable3[2][3], 12);
    ASSERT_EQUAL(integerTable3[3][0], 13);
    ASSERT_EQUAL(integerTable3[3][1], 14);
    ASSERT_EQUAL(integerTable3[3][2], 15);
    ASSERT_EQUAL(integerTable3[3][3], 16);

#include STSTEM_WARNING_POP
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
