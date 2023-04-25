///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 17:08)

#include "TupleTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

#define COMPILE_ERROR_TEST

#undef COMPILE_ERROR_TEST

CoreTools::TupleTesting::TupleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TupleTesting)

void CoreTools::TupleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TupleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompileErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ForEachTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::TupleTesting::IntegerTest()
{
    // 固定值测试
    Tuple<4, int> tuple0{};

    // 测试默认构造函数
    ASSERT_EQUAL(tuple0[0], 0);
    ASSERT_EQUAL(tuple0[1], 0);
    ASSERT_EQUAL(tuple0[2], 0);
    ASSERT_EQUAL(tuple0[3], 0);

    tuple0[0] = 1;
    tuple0[1] = 22;
    tuple0[2] = 334;
    tuple0[3] = 44;

    ASSERT_EQUAL(tuple0[0], 1);
    ASSERT_EQUAL(tuple0[1], 22);
    ASSERT_EQUAL(tuple0[2], 334);
    ASSERT_EQUAL(tuple0[3], 44);

    Tuple tuple1{ tuple0 };

    // 测试复制构造函数
    ASSERT_EQUAL(tuple1[0], 1);
    ASSERT_EQUAL(tuple1[1], 22);
    ASSERT_EQUAL(tuple1[2], 334);
    ASSERT_EQUAL(tuple1[3], 44);

    tuple1[0] = 121;
    tuple1[1] = 2221;
    tuple1[2] = 3343;
    tuple1[3] = 442;

    ASSERT_EQUAL(tuple1[0], 121);
    ASSERT_EQUAL(tuple1[1], 2221);
    ASSERT_EQUAL(tuple1[2], 3343);
    ASSERT_EQUAL(tuple1[3], 442);

    ASSERT_EQUAL(tuple0[0], 1);
    ASSERT_EQUAL(tuple0[1], 22);
    ASSERT_EQUAL(tuple0[2], 334);
    ASSERT_EQUAL(tuple0[3], 44);

    // 测试赋值运算符
    tuple0 = tuple1;

    ASSERT_EQUAL(tuple0[0], 121);
    ASSERT_EQUAL(tuple0[1], 2221);
    ASSERT_EQUAL(tuple0[2], 3343);
    ASSERT_EQUAL(tuple0[3], 442);
}

void CoreTools::TupleTesting::StringTest()
{
    // 固定值测试
    Tuple<2, std::string> tuple0{};

    // 测试默认构造函数
    ASSERT_EQUAL(tuple0[0], "");
    ASSERT_EQUAL(tuple0[1], "");

    tuple0[0] = "first";
    tuple0[1] = "second";

    ASSERT_EQUAL(tuple0[0], "first");
    ASSERT_EQUAL(tuple0[1], "second");

    Tuple tuple1{ tuple0 };

    // 测试复制构造函数
    ASSERT_EQUAL(tuple1[0], "first");
    ASSERT_EQUAL(tuple1[1], "second");

    tuple1[0] = "second";
    tuple1[1] = "first";

    ASSERT_EQUAL(tuple0[0], "first");
    ASSERT_EQUAL(tuple0[1], "second");
    ASSERT_EQUAL(tuple1[0], "second");
    ASSERT_EQUAL(tuple1[1], "first");

    tuple0 = tuple1;

    ASSERT_EQUAL(tuple0[0], "second");
    ASSERT_EQUAL(tuple0[1], "first");
    ASSERT_EQUAL(tuple1[0], "second");
    ASSERT_EQUAL(tuple1[1], "first");

    // 测试赋值运算符
    ASSERT_EQUAL(tuple0[0], "second");
    ASSERT_EQUAL(tuple0[1], "first");
}

void CoreTools::TupleTesting::OperatorTest()
{
    Tuple<4, int> lhsTuple{};
    Tuple<4, int> rhsTuple{};

    lhsTuple[0] = 0;
    lhsTuple[1] = 0;
    lhsTuple[2] = 0;
    lhsTuple[3] = 0;
    rhsTuple[0] = 0;
    rhsTuple[1] = 0;
    rhsTuple[2] = 0;
    rhsTuple[3] = 0;

    ASSERT_TRUE(lhsTuple == rhsTuple);
    ASSERT_FALSE(lhsTuple != rhsTuple);

    lhsTuple[0] = 1;

    ASSERT_TRUE(rhsTuple < lhsTuple);
    ASSERT_TRUE(rhsTuple <= lhsTuple);
    ASSERT_TRUE(lhsTuple > rhsTuple);
    ASSERT_TRUE(lhsTuple >= rhsTuple);
}

void CoreTools::TupleTesting::ConstructorTest()
{
    Tuple<1, int> tuple0{ 5 };

    ASSERT_EQUAL(tuple0[0], 5);

    Tuple<2, std::string> tuple1{ "first", "second" };

    ASSERT_EQUAL(tuple1[0], "first");
    ASSERT_EQUAL(tuple1[1], "second");

    const Tuple<3, Tuple<2, uint32_t>> tuple2{ Tuple<2, uint32_t>{ 5, 8 }, Tuple<2, uint32_t>{ 6, 9 }, Tuple<2, uint32_t>{ 1, 5 } };

    Tuple<4, char> tuple3{ 'm', 'u', 'i', 'p' };

    ASSERT_EQUAL(tuple3[0], 'm');
    ASSERT_EQUAL(tuple3[1], 'u');
    ASSERT_EQUAL(tuple3[2], 'i');
    ASSERT_EQUAL(tuple3[3], 'p');
}

void CoreTools::TupleTesting::CompileErrorTest() noexcept
{
#ifdef COMPILE_ERROR_TEST

    // 以下代码无法通过编译
    Tuple<1, int> tuple0{ 5, 6 };
    Tuple<2, int> tuple1{ 5, 6, 7 };
    Tuple<3, int> tuple2{ 5, 6, 7, 8 };
    Tuple<4, int> tuple3{ 5 };

#endif  // COMPILE_ERROR_TEST
}

void CoreTools::TupleTesting::ForEachTest()
{
    const Tuple<4, int> tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto value : tuple)
    {
        ASSERT_EQUAL(value, index);

        ++index;
    }
}

void CoreTools::TupleTesting::SumTest()
{
    const Tuple<4, int> tuple{ 1, 2, 3, 4 };

    auto sum = 0;
    for (const auto value : tuple)
    {
        sum += value;
    }

    ASSERT_EQUAL(sum, tuple.GetSum());
}
