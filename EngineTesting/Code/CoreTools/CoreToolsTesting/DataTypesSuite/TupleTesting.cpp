/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 13:02)

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
    /// 固定值测试
    Tuple4 tuple0{};

    /// 测试默认构造函数
    ASSERT_NOT_THROW_EXCEPTION_1(IntegerZeroTest, tuple0);

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerAssignment, tuple0, 1);
    ASSERT_NOT_THROW_EXCEPTION_2(IntegerOriginalTest, tuple0, 1);

    Tuple tuple1{ tuple0 };

    /// 测试复制构造函数
    ASSERT_NOT_THROW_EXCEPTION_2(IntegerOriginalTest, tuple1, 1);

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerAssignment, tuple1, 4);
    ASSERT_NOT_THROW_EXCEPTION_2(IntegerOriginalTest, tuple1, 4);
    ASSERT_NOT_THROW_EXCEPTION_2(IntegerOriginalTest, tuple0, 1);

    /// 测试赋值运算符
    tuple0 = tuple1;

    ASSERT_NOT_THROW_EXCEPTION_2(IntegerOriginalTest, tuple0, 4);
}

void CoreTools::TupleTesting::IntegerZeroTest(const Tuple4& tuple)
{
    for (auto i = 0; i < Tuple4::tupleDimension; ++i)
    {
        ASSERT_EQUAL(tuple[i], 0);
    }
}

void CoreTools::TupleTesting::IntegerAssignment(Tuple4& tuple, int value)
{
    for (auto i = 0; i < Tuple4::tupleDimension; ++i)
    {
        tuple[i] = value + i;
    }
}

void CoreTools::TupleTesting::IntegerOriginalTest(const Tuple4& tuple, int value)
{
    for (auto i = 0; i < Tuple4::tupleDimension; ++i)
    {
        ASSERT_EQUAL(tuple[i], value + i);
    }
}

void CoreTools::TupleTesting::StringTest()
{
    /// 固定值测试
    StringTuple2 tuple0{};

    /// 测试默认构造函数
    ASSERT_NOT_THROW_EXCEPTION_1(StringZeroTest, tuple0);

    ASSERT_NOT_THROW_EXCEPTION_2(StringAssignment, tuple0, 0);

    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple0, 0);

    Tuple tuple1{ tuple0 };

    /// 测试复制构造函数
    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple1, 0);

    ASSERT_NOT_THROW_EXCEPTION_2(StringAssignment, tuple1, 2);
    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple0, 0);
    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple1, 2);

    /// 测试赋值运算符
    tuple0 = tuple1;

    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple0, 2);
    ASSERT_NOT_THROW_EXCEPTION_2(StringOriginalTest, tuple1, 2);
}

void CoreTools::TupleTesting::StringZeroTest(const StringTuple2& tuple)
{
    for (auto i = 0; i < StringTuple2::tupleDimension; ++i)
    {
        ASSERT_TRUE(tuple[i].empty());
    }
}

void CoreTools::TupleTesting::StringAssignment(StringTuple2& tuple, int value)
{
    for (auto i = 0; i < StringTuple2::tupleDimension; ++i)
    {
        tuple[i] = "test" + std::to_string(value + i);
    }
}

void CoreTools::TupleTesting::StringOriginalTest(const StringTuple2& tuple, int value)
{
    for (auto i = 0; i < StringTuple2::tupleDimension; ++i)
    {
        ASSERT_EQUAL(tuple[i], "test" + std::to_string(value + i));
    }
}

void CoreTools::TupleTesting::OperatorTest()
{
    Tuple4 lhsTuple = CreateTuple4();
    const Tuple4 rhsTuple = CreateTuple4();

    ASSERT_TRUE(lhsTuple == rhsTuple);
    ASSERT_FALSE(lhsTuple != rhsTuple);
    ASSERT_FALSE(rhsTuple < lhsTuple);
    ASSERT_TRUE(rhsTuple <= lhsTuple);
    ASSERT_FALSE(lhsTuple > rhsTuple);
    ASSERT_TRUE(lhsTuple >= rhsTuple);

    lhsTuple[0] = 1;

    ASSERT_FALSE(lhsTuple == rhsTuple);
    ASSERT_TRUE(lhsTuple != rhsTuple);
    ASSERT_TRUE(rhsTuple < lhsTuple);
    ASSERT_TRUE(rhsTuple <= lhsTuple);
    ASSERT_TRUE(lhsTuple > rhsTuple);
    ASSERT_TRUE(lhsTuple >= rhsTuple);
}

CoreTools::TupleTesting::Tuple4 CoreTools::TupleTesting::CreateTuple4()
{
    Tuple4 tuple{};

    for (auto i = 0; i < Tuple4::tupleDimension; ++i)
    {
        tuple[i] = i;
    }

    return tuple;
}

void CoreTools::TupleTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Constructor3Test);
}

void CoreTools::TupleTesting::Constructor0Test()
{
    Tuple1 tuple{ 5 };

    ASSERT_EQUAL(tuple[0], 5);
}

void CoreTools::TupleTesting::Constructor1Test()
{
    Tuple<2, std::string> tuple{ "test0", "test1" };

    ASSERT_EQUAL(tuple[0], "test0");
    ASSERT_EQUAL(tuple[1], "test1");
}

void CoreTools::TupleTesting::Constructor2Test()
{
    const Tuple<3, Tuple2> tuple{ Tuple2{ 1, 2 }, Tuple2{ 3, 4 }, Tuple2{ 5, 6 } };

    ASSERT_EQUAL(tuple[0][0], 1);
    ASSERT_EQUAL(tuple[0][1], 2);
    ASSERT_EQUAL(tuple[1][0], 3);
    ASSERT_EQUAL(tuple[1][1], 4);
    ASSERT_EQUAL(tuple[2][0], 5);
    ASSERT_EQUAL(tuple[2][1], 6);
}

void CoreTools::TupleTesting::Constructor3Test()
{
    Tuple<4, char> tuple{ 'a', 'b', 'c', 'd' };

    ASSERT_EQUAL(tuple[0], 'a');
    ASSERT_EQUAL(tuple[1], 'b');
    ASSERT_EQUAL(tuple[2], 'c');
    ASSERT_EQUAL(tuple[3], 'd');
}

void CoreTools::TupleTesting::CompileErrorTest() noexcept
{
#ifdef COMPILE_ERROR_TEST

    /// 以下代码无法通过编译
    Tuple1 tuple0{ 5, 6 };
    Tuple2 tuple1{ 5, 6, 7 };
    Tuple3 tuple2{ 5, 6, 7, 8 };
    Tuple4 tuple3{ 5 };

#endif  // COMPILE_ERROR_TEST
}

void CoreTools::TupleTesting::ForEachTest()
{
    const Tuple4 tuple{ 1, 2, 3, 4 };

    auto index = 1;
    for (const auto element : tuple)
    {
        ASSERT_EQUAL(element, index);

        ++index;
    }
}

void CoreTools::TupleTesting::SumTest()
{
    const Tuple4 tuple{ 1, 2, 3, 4 };

    auto sum = 0;
    for (const auto element : tuple)
    {
        sum += element;
    }

    ASSERT_EQUAL(sum, tuple.GetSum());
}
