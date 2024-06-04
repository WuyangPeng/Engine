/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 09:47)

#include "TinyTesting.h"
#include "Detail/TinyTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Tiny.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define TINY_COMPILE_ERROR

#undef TINY_COMPILE_ERROR

CoreTools::TinyTesting::TinyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TinyTesting)

void CoreTools::TinyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TinyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PushBackTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClearTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PushFrontTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IteratorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EraseTest);
}

void CoreTools::TinyTesting::InitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InitEmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InitFrontBackTest);
}

void CoreTools::TinyTesting::InitSizeTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char>;
    using Tiny2 = Tiny<char, long>;
    using Tiny3 = Tiny<char, char, int>;

    constexpr BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny0>::value, ==, 0);
    constexpr BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny1>::value, ==, 1);
    constexpr BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny2>::value, ==, 2);
    constexpr BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny3>::value, ==, 3);
}

void CoreTools::TinyTesting::InitEmptyTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char>;
    using Tiny2 = Tiny<char, long>;
    using Tiny3 = Tiny<char, char, int>;

    constexpr BOOST_MPL_ASSERT((boost::mpl::empty<Tiny0>));
    constexpr BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny1>));
    constexpr BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny2>));
    constexpr BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny3>));
}

void CoreTools::TinyTesting::InitFrontBackTest() noexcept
{
    using Tiny0 = Tiny<char>;
    using Tiny1 = Tiny<char, long>;
    using Tiny2 = Tiny<char, char, int>;

    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny0>::type, char>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny0>::type, char>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny1>::type, char>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny1>::type, long>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny2>::type, char>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny2>::type, int>));
}

void CoreTools::TinyTesting::PushBackTest() noexcept
{
    using Tiny0 = Tiny<>;

    using Tiny1 = boost::mpl::push_back<Tiny0, int>::type;
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny1>::type, int>));

    using Tiny2 = boost::mpl::push_front<Tiny1, char>::type;
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny2>::type, int>));
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny2>::type, char>));

    using Tiny3 = boost::mpl::push_back<Tiny2, long>::type;
    constexpr BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny3>::type, long>));

    MAYBE_UNUSED constexpr TinyTest<Tiny0>::type tiny0{};
    MAYBE_UNUSED constexpr TinyTest<Tiny1>::type tiny1{};
    MAYBE_UNUSED constexpr TinyTest<Tiny2>::type tiny2{};
    MAYBE_UNUSED constexpr TinyTest<Tiny3>::type tiny3{};

    using Tiny4 = boost::mpl::push_back<Tiny0, char>::type;
    using Tiny5 = boost::mpl::push_back<Tiny4, int>::type;
    using Tiny6 = boost::mpl::push_back<Tiny2, long>::type;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidTiny = boost::mpl::push_back<Tiny3, int>::type;

#endif  // TINY_COMPILE_ERROR

    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny2>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny3>::type::value));
}

void CoreTools::TinyTesting::ClearTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<unsigned short, double&, bool>;

    MAYBE_UNUSED constexpr TinyTest<Tiny0>::type tiny0{};
    MAYBE_UNUSED constexpr TinyTest<Tiny1>::type tiny1{};

    using Clean = boost::mpl::clear<Tiny1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny0, Clean>::type::value));
}

void CoreTools::TinyTesting::PushFrontTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char*>;
    using Tiny2 = Tiny<const long, char*>;
    using Tiny3 = Tiny<unsigned short&, const long, char*>;

    MAYBE_UNUSED constexpr TinyTest<Tiny0>::type tiny0{};
    MAYBE_UNUSED constexpr TinyTest<Tiny1>::type tiny1{};
    MAYBE_UNUSED constexpr TinyTest<Tiny2>::type tiny2{};
    MAYBE_UNUSED constexpr TinyTest<Tiny3>::type tiny3{};

    using Tiny4 = boost::mpl::push_front<Tiny0, char*>::type;
    using Tiny5 = boost::mpl::push_front<Tiny1, const long>::type;
    using Tiny6 = boost::mpl::push_front<Tiny2, unsigned short&>::type;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidTiny = boost::mpl::push_front<Tiny3, int>::type;

#endif  // TINY_COMPILE_ERROR

    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny1>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny2>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny3>::type::value));
}

void CoreTools::TinyTesting::EmptyTest() noexcept
{
    using Tiny0 = Tiny<>;

    MAYBE_UNUSED constexpr TinyTest<Tiny0>::type tiny0{};

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType0 = boost::mpl::at<Tiny0, TinyZero>::type;

#endif  // TINY_COMPILE_ERROR

    using Beg = boost::mpl::begin<Tiny0>::type;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType1 = boost::mpl::next<Beg>::type;

#endif  // TINY_COMPILE_ERROR

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType2 = boost::mpl::deref<Beg>::type;

#endif  // TINY_COMPILE_ERROR

    using End = boost::mpl::end<Tiny0>::type;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType3 = boost::mpl::prior<End>::type;

#endif  // TINY_COMPILE_ERROR

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType4 = boost::mpl::advance<Beg, TinyOne>::type;

#endif  // TINY_COMPILE_ERROR

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType5 = boost::mpl::advance<End, boost::mpl::int_<-1>>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::IteratorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Iterator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Iterator1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Iterator2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Iterator3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Iterator4Test);
}

void CoreTools::TinyTesting::Iterator0Test() noexcept
{
    using TinyType = Tiny<>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using TinyIterator1 = boost::mpl::insert<TinyType, TinyIterator0, long>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<long>>::type::value));

    using TinyIterator2 = TinyIterator<TinyIterator1, TinyZero>;
    using TinyIterator3 = boost::mpl::insert<TinyIterator1, TinyIterator2, int>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator3, Tiny<int, long>>::type::value));

    using TinyIterator4 = TinyIterator<TinyIterator3, TinyZero>;
    using TinyIterator5 = boost::mpl::insert<TinyIterator3, TinyIterator4, char>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator5, Tiny<char, int, long>>::type::value));

    using TinyIterator6 = TinyIterator<TinyIterator5, TinyZero>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidTinyIterator = boost::mpl::insert<TinyIterator5, TinyIterator6, bool>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Iterator1Test() noexcept
{
    using TinyType = Tiny<int>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyOne>;
    using TinyIterator1 = boost::mpl::insert<TinyType, TinyIterator0, long>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<int, long>>::type::value));

    using TinyIterator2 = TinyIterator<TinyIterator1, TinyOne>;
    using TinyIterator3 = boost::mpl::insert<TinyIterator1, TinyIterator2, char>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator3, Tiny<int, char, long>>::type::value));
    using TinyIterator4 = TinyIterator<TinyIterator3, TinyOne>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidTinyIterator = boost::mpl::insert<TinyIterator3, TinyIterator4, bool>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Iterator2Test() noexcept
{
    using TinyType = Tiny<char*, const long>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyTwo>;
    using TinyIterator1 = boost::mpl::insert<TinyType, TinyIterator0, long>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<char*, const long, long>>::type::value));
    using TinyIterator2 = TinyIterator<TinyIterator1, TinyTwo>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidTinyIterator = boost::mpl::insert<TinyIterator1, TinyIterator2, char>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Iterator3Test() noexcept
{
    using Tiny0 = Tiny<int>;
    using Tiny1 = Tiny<char*, const long>;
    using Tiny2 = Tiny<unsigned short&, const long, char*>;

    MAYBE_UNUSED constexpr TinyTest<Tiny2>::type tiny{};

    using Tiny3 = boost::mpl::pop_front<Tiny2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny3, Tiny<const long, char*>>::type::value));
    using Tiny4 = boost::mpl::pop_front<Tiny1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny<const long>>::type::value));
    using Tiny5 = boost::mpl::pop_front<Tiny0>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny<>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType = boost::mpl::pop_front<Tiny0>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Iterator4Test() noexcept
{
    using Tiny0 = Tiny<int>;
    using Tiny1 = Tiny<char*, const long>;
    using Tiny2 = Tiny<unsigned short&, const long, char*>;

    using Tiny3 = boost::mpl::pop_back<Tiny2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny3, Tiny<unsigned short&, const long>>::type::value));
    using Tiny4 = boost::mpl::pop_back<Tiny1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny<char*>>::type::value));
    using Tiny5 = boost::mpl::pop_back<Tiny0>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny<>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using InvalidType = boost::mpl::pop_back<Tiny5>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::EraseTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Empty0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty6Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Empty7Test);
}

void CoreTools::TinyTesting::Empty0Test() noexcept
{
    using TinyType = Tiny<unsigned short&, const long, char*>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using Erase0 = boost::mpl::erase<TinyType, TinyIterator0>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<const long, char*>>::type::value));

    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;
    using Erase1 = boost::mpl::erase<TinyType, TinyIterator1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<unsigned short&, char*>>::type::value));

    using TinyIterator2 = TinyIterator<TinyType, TinyTwo>;

    using Erase2 = boost::mpl::erase<TinyType, TinyIterator2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<unsigned short&, const long>>::type::value));
}

void CoreTools::TinyTesting::Empty1Test() noexcept
{
    using TinyType = Tiny<const long, char*>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using Erase0 = boost::mpl::erase<TinyType, TinyIterator0>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<char*>>::type::value));

    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;
    using Erase1 = boost::mpl::erase<TinyType, TinyIterator1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<const long>>::type::value));

    using TinyIterator2 = TinyIterator<TinyType, TinyTwo>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid = boost::mpl::erase<TinyType, TinyIterator2>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Empty2Test() noexcept
{
    using TinyType = Tiny<char*>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using EraseType = boost::mpl::erase<TinyType, TinyIterator0>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<EraseType, Tiny<>>::type::value));

    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid = boost::mpl::erase<TinyType, TinyIterator1>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Empty3Test() noexcept
{
    using TinyType = Tiny<>;
    MAYBE_UNUSED constexpr TinyTest<TinyType>::type tiny{};

    using TinyIterator = TinyIterator<TinyType, TinyZero>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid = boost::mpl::erase<TinyType, TinyIterator>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Empty4Test() noexcept
{
    using TinyType = Tiny<unsigned short&, const long, char*>;

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;
    using TinyIterator2 = TinyIterator<TinyType, TinyTwo>;
    using TinyIterator3 = TinyIterator<TinyType, TinyThree>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid0 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator0>::type;

#endif  // TINY_COMPILE_ERROR

    using Erase0 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<const long, char*>>::type::value));

    using Erase1 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<char*>>::type::value));

    using Erase2 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator3>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid1 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator1>::type;

#endif  // TINY_COMPILE_ERROR

    using Erase3 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase3, Tiny<unsigned short&, char*>>::type::value));

    using Erase4 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator3>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase4, Tiny<unsigned short&>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid2 = boost::mpl::erase<TinyType, TinyIterator2, TinyIterator2>::type;

#endif  // TINY_COMPILE_ERROR

    using Erase5 = boost::mpl::erase<TinyType, TinyIterator2, TinyIterator3>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase5, Tiny<unsigned short&, const long>>::type::value));
}

void CoreTools::TinyTesting::Empty5Test() noexcept
{
    using TinyType = Tiny<const long, char*>;

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;
    using TinyIterator2 = TinyIterator<TinyType, TinyTwo>;
    using TinyIterator3 = TinyIterator<TinyType, TinyThree>;

    using Erase0 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<char*>>::type::value));

    using Erase1 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid0 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator3>::type;

#endif  // TINY_COMPILE_ERROR

    using Erase2 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator2>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<const long>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid1 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator3>::type;

#endif  // TINY_COMPILE_ERROR

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid2 = boost::mpl::erase<TinyType, TinyIterator2, TinyIterator3>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Empty6Test() noexcept
{
    using TinyType = Tiny<char*>;

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;
    using TinyIterator2 = TinyIterator<TinyType, TinyTwo>;

    using EraseType = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<EraseType, Tiny<>>::type::value));

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid0 = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator2>::type;

#endif  // TINY_COMPILE_ERROR

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid1 = boost::mpl::erase<TinyType, TinyIterator1, TinyIterator2>::type;

#endif  // TINY_COMPILE_ERROR
}

void CoreTools::TinyTesting::Empty7Test() noexcept
{
    using TinyType = Tiny<>;

    using TinyIterator0 = TinyIterator<TinyType, TinyZero>;
    using TinyIterator1 = TinyIterator<TinyType, TinyOne>;

#ifdef TINY_COMPILE_ERROR  // 这里应该产生编译错误。

    using Invalid = boost::mpl::erase<TinyType, TinyIterator0, TinyIterator1>::type;

#endif  // TINY_COMPILE_ERROR
}