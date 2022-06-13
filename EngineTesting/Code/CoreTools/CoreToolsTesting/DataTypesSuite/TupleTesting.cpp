///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:10)

#include "TupleTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <string>

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TupleTesting)

void CoreTools::TupleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompileErrorTest);
}

void CoreTools::TupleTesting::IntegerTest()
{
    // 固定值测试
    Tuple<4, int> integerTuple1{};

    // 测试默认构造函数
    ASSERT_EQUAL(integerTuple1[0], 0);
    ASSERT_EQUAL(integerTuple1[1], 0);
    ASSERT_EQUAL(integerTuple1[2], 0);
    ASSERT_EQUAL(integerTuple1[3], 0);

    integerTuple1[0] = 1;
    integerTuple1[1] = 22;
    integerTuple1[2] = 334;
    integerTuple1[3] = 44;

    ASSERT_EQUAL(integerTuple1[0], 1);
    ASSERT_EQUAL(integerTuple1[1], 22);
    ASSERT_EQUAL(integerTuple1[2], 334);
    ASSERT_EQUAL(integerTuple1[3], 44);

    Tuple<4, int> integerTuple2{ integerTuple1 };

    // 测试复制构造函数
    ASSERT_EQUAL(integerTuple2[0], 1);
    ASSERT_EQUAL(integerTuple2[1], 22);
    ASSERT_EQUAL(integerTuple2[2], 334);
    ASSERT_EQUAL(integerTuple2[3], 44);

    integerTuple2[0] = 121;
    integerTuple2[1] = 2221;
    integerTuple2[2] = 3343;
    integerTuple2[3] = 442;

    ASSERT_EQUAL(integerTuple2[0], 121);
    ASSERT_EQUAL(integerTuple2[1], 2221);
    ASSERT_EQUAL(integerTuple2[2], 3343);
    ASSERT_EQUAL(integerTuple2[3], 442);

    ASSERT_EQUAL(integerTuple1[0], 1);
    ASSERT_EQUAL(integerTuple1[1], 22);
    ASSERT_EQUAL(integerTuple1[2], 334);
    ASSERT_EQUAL(integerTuple1[3], 44);

    // 测试赋值运算符
    integerTuple1 = integerTuple2;

    ASSERT_EQUAL(integerTuple1[0], 121);
    ASSERT_EQUAL(integerTuple1[1], 2221);
    ASSERT_EQUAL(integerTuple1[2], 3343);
    ASSERT_EQUAL(integerTuple1[3], 442);
}

void CoreTools::TupleTesting::StringTest()
{
    // 固定值测试
    Tuple<2, string> stringTuple1{};

    // 测试默认构造函数
    ASSERT_EQUAL(stringTuple1[0], "");
    ASSERT_EQUAL(stringTuple1[1], "");

    stringTuple1[0] = "first";
    stringTuple1[1] = "second";

    ASSERT_EQUAL(stringTuple1[0], "first");
    ASSERT_EQUAL(stringTuple1[1], "second");

    Tuple<2, string> stringTuple2{ stringTuple1 };

    // 测试复制构造函数
    ASSERT_EQUAL(stringTuple2[0], "first");
    ASSERT_EQUAL(stringTuple2[1], "second");

    stringTuple2[0] = "second";
    stringTuple2[1] = "first";

    ASSERT_EQUAL(stringTuple1[0], "first");
    ASSERT_EQUAL(stringTuple1[1], "second");
    ASSERT_EQUAL(stringTuple2[0], "second");
    ASSERT_EQUAL(stringTuple2[1], "first");

    stringTuple1 = stringTuple2;

    ASSERT_EQUAL(stringTuple1[0], "second");
    ASSERT_EQUAL(stringTuple1[1], "first");
    ASSERT_EQUAL(stringTuple2[0], "second");
    ASSERT_EQUAL(stringTuple2[1], "first");

    // 测试赋值运算符
    ASSERT_EQUAL(stringTuple1[0], "second");
    ASSERT_EQUAL(stringTuple1[1], "first");
}

void CoreTools::TupleTesting::OperatorTest()
{
    Tuple<4, long> longTuple1{};
    Tuple<4, long> longTuple2{};

    longTuple1[0] = 0;
    longTuple1[1] = 0;
    longTuple1[2] = 0;
    longTuple1[3] = 0;
    longTuple2[0] = 0;
    longTuple2[1] = 0;
    longTuple2[2] = 0;
    longTuple2[3] = 0;

    ASSERT_TRUE(longTuple1 == longTuple2);
    ASSERT_FALSE(longTuple1 != longTuple2);

    longTuple1[0] = 1;

    ASSERT_TRUE(longTuple2 < longTuple1);
    ASSERT_TRUE(longTuple2 <= longTuple1);
    ASSERT_TRUE(longTuple1 > longTuple2);
    ASSERT_TRUE(longTuple1 >= longTuple2);
}

void CoreTools::TupleTesting::ConstructorTest()
{
    Tuple<1, int> tuple1{ 5 };

    ASSERT_EQUAL(tuple1[0], 5);

    Tuple<2, string> tuple2{ "first", "second" };

    ASSERT_EQUAL(tuple2[0], "first");
    ASSERT_EQUAL(tuple2[1], "second");

    const Tuple<3, Tuple<2, unsigned int>> tuple3{ Tuple<2, unsigned int>{ 5, 8 },
                                                   Tuple<2, unsigned int>{ 6, 9 },
                                                   Tuple<2, unsigned int>{ 1, 5 } };

    Tuple<4, char> tuple4{ 'm', 'u', 'i', 'p' };

    ASSERT_EQUAL(tuple4[0], 'm');
    ASSERT_EQUAL(tuple4[1], 'u');
    ASSERT_EQUAL(tuple4[2], 'i');
    ASSERT_EQUAL(tuple4[3], 'p');
}

void CoreTools::TupleTesting::CompileErrorTest() noexcept
{
#ifdef COMPILE_ERROR_TEST

    // 以下代码无法通过编译
    Tuple<1, int> tuple1{ 5, 6 };
    Tuple<2, int> tuple2{ 5, 6, 7 };
    Tuple<3, int> tuple3{ 5, 6, 7, 8 };
    Tuple<4, int> tuple4{ 5 };

#endif  // COMPILE_ERROR_TEST
}
