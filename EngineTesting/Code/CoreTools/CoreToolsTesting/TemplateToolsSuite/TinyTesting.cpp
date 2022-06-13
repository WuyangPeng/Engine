///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:08)

#include "TinyTesting.h"
#include "Detail/TinyTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Tiny.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TinyTesting)

void CoreTools::TinyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PushBackTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClearTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PushFrontTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InteratorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EraseTest);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26814)

void CoreTools::TinyTesting::InitTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char>;
    using Tiny2 = Tiny<char, long>;
    using Tiny3 = Tiny<char, char, int>;

    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny0>::value, ==, 0);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny1>::value, ==, 1);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny2>::value, ==, 2);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<Tiny3>::value, ==, 3);

    BOOST_MPL_ASSERT((boost::mpl::empty<Tiny0>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny1>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny2>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<Tiny3>));

    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny1>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny1>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny2>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny2>::type, long>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny3>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny3>::type, int>));
}

void CoreTools::TinyTesting::PushBackTest() noexcept
{
    using Tiny0 = Tiny<>;

    using Tiny1 = boost::mpl::push_back<Tiny0, int>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny1>::type, int>));

    using Tiny2 = boost::mpl::push_front<Tiny1, char>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny2>::type, int>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<Tiny2>::type, char>));

    using Tiny3 = boost::mpl::push_back<Tiny2, long>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<Tiny3>::type, long>));

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny0{};
    MAYBE_UNUSED TinyTest<Tiny1>::type tiny1{};
    MAYBE_UNUSED TinyTest<Tiny2>::type tiny2{};
    MAYBE_UNUSED TinyTest<Tiny3>::type tiny3{};

    using Tiny4 = boost::mpl::push_back<Tiny0, char>::type;
    using Tiny5 = boost::mpl::push_back<Tiny4, int>::type;
    using Tiny6 = boost::mpl::push_back<Tiny2, long>::type;

#if 0  // 这里应该产生编译错误。

	using InvalidTiny = boost::mpl::push_back<Tiny3, int>::type;

#endif  // 0

    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny2>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny3>::type::value));
}

#include STSTEM_WARNING_POP

void CoreTools::TinyTesting::ClearTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<unsigned short, double&, bool>;

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny0;
    MAYBE_UNUSED TinyTest<Tiny1>::type tiny1;

    using Clean = boost::mpl::clear<Tiny1>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny0, Clean>::type::value));
}

void CoreTools::TinyTesting::PushFrontTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char*>;
    using Tiny2 = Tiny<const long, char*>;
    using Tiny3 = Tiny<unsigned short&, const long, char*>;

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny0;
    MAYBE_UNUSED TinyTest<Tiny1>::type tiny1;
    MAYBE_UNUSED TinyTest<Tiny2>::type tiny2;
    MAYBE_UNUSED TinyTest<Tiny3>::type tiny3;

    using Tiny4 = boost::mpl::push_front<Tiny0, char*>::type;
    using Tiny5 = boost::mpl::push_front<Tiny1, const long>::type;
    using Tiny6 = boost::mpl::push_front<Tiny2, unsigned short&>::type;

#if 0  // 这里应该产生编译错误。

	using InvalidTiny = boost::mpl::push_front<Tiny3, int>::type;

#endif  // 0

    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny1>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny2>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny3>::type::value));
}

void CoreTools::TinyTesting::EmptyTest() noexcept
{
    using Tiny0 = Tiny<>;

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny0;

#if 0  // 这里应该产生编译错误。

	using invalidType0 = boost::mpl::at<Tiny0, TinyZero>::type;

#endif  // 0

    using Beg = boost::mpl::begin<Tiny0>::type;

#if 0  // 这里应该产生编译错误。

	using invalidType1 = boost::mpl::next<Beg>::type;

#endif  // 0

#if 0  // 这里应该产生编译错误。

	using invalidType2 = boost::mpl::deref<Beg>::type;

#endif  // 0

    using End = boost::mpl::end<Tiny0>::type;

#if 0  // 这里应该产生编译错误。

	using invalidType3 = boost::mpl::prior<End>::type;

#endif  // 0

#if 0  // 这里应该产生编译错误。

	using invalidType4 = boost::mpl::advance<Beg, TinyOne>::type;

#endif  // 0

#if 0  // 这里应该产生编译错误。

	using invalidType5 = boost::mpl::advance<End, boost::mpl::int_<-1>>::type;

#endif  // 0
}

void CoreTools::TinyTesting::InteratorTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<int>;
    using Tiny2 = Tiny<char*, const long>;
    using Tiny3 = Tiny<unsigned short&, const long, char*>;

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny1;
    MAYBE_UNUSED TinyTest<Tiny1>::type tiny2;
    MAYBE_UNUSED TinyTest<Tiny2>::type tiny3;
    MAYBE_UNUSED TinyTest<Tiny3>::type tiny4;

    {
        using TinyIterator0 = TinyIterator<Tiny0, TinyZero>;
        using TinyIterator1 = boost::mpl::insert<Tiny0, TinyIterator0, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<long>>::type::value));

        using TinyIterator2 = TinyIterator<TinyIterator1, TinyZero>;
        using TinyIterator3 = boost::mpl::insert<TinyIterator1, TinyIterator2, int>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator3, Tiny<int, long>>::type::value));

        using TinyIterator4 = TinyIterator<TinyIterator3, TinyZero>;
        using TinyIterator5 = boost::mpl::insert<TinyIterator3, TinyIterator4, char>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator5, Tiny<char, int, long>>::type::value));

        using TinyIterator6 = TinyIterator<TinyIterator5, TinyZero>;

#if 0  // 这里应该产生编译错误。

		using InvalidTinyIterator = boost::mpl::insert<TinyIterator5, TinyIterator6, bool>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny1, TinyOne>;
        using TinyIterator1 = boost::mpl::insert<Tiny1, TinyIterator0, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<int, long>>::type::value));

        using TinyIterator2 = TinyIterator<TinyIterator1, TinyOne>;
        using TinyIterator3 = boost::mpl::insert<TinyIterator1, TinyIterator2, char>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator3, Tiny<int, char, long>>::type::value));
        using TinyIterator4 = TinyIterator<TinyIterator3, TinyOne>;

#if 0  // 这里应该产生编译错误。

        using InvalidTinyIterator = boost::mpl::insert<TinyIterator3, TinyIterator4, bool>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny2, TinyTwo>;
        using TinyIterator1 = boost::mpl::insert<Tiny2, TinyIterator0, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<TinyIterator1, Tiny<char*, const long, long>>::type::value));
        using TinyIterator2 = TinyIterator<TinyIterator1, TinyTwo>;

#if 0  // 这里应该产生编译错误。

		using InvalidTinyIterator = boost::mpl::insert<TinyIterator1, TinyIterator2, char>::type;

#endif  // 0
    }

    {
        using Tiny4 = boost::mpl::pop_front<Tiny3>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny<const long, char*>>::type::value));
        using Tiny5 = boost::mpl::pop_front<Tiny2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny<const long>>::type::value));
        using Tiny6 = boost::mpl::pop_front<Tiny1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。		

		using InvalidType = boost::mpl::pop_front<Tiny0>::type;

#endif  // 0
    }

    {
        using Tiny4 = boost::mpl::pop_back<Tiny3>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny4, Tiny<unsigned short&, const long>>::type::value));
        using Tiny5 = boost::mpl::pop_back<Tiny2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny5, Tiny<char*>>::type::value));
        using Tiny6 = boost::mpl::pop_back<Tiny1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Tiny6, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。	

		using InvalidType = boost::mpl::pop_back<Tiny6>::type;

#endif  // 0
    }
}

void CoreTools::TinyTesting::EraseTest() noexcept
{
    using Tiny0 = Tiny<>;
    using Tiny1 = Tiny<char*>;
    using Tiny2 = Tiny<const long, char*>;
    using Tiny3 = Tiny<unsigned short&, const long, char*>;

    MAYBE_UNUSED TinyTest<Tiny0>::type tiny1;
    MAYBE_UNUSED TinyTest<Tiny1>::type tiny2;
    MAYBE_UNUSED TinyTest<Tiny2>::type tiny3;
    MAYBE_UNUSED TinyTest<Tiny3>::type tiny4;

    {
        using TinyIterator0 = TinyIterator<Tiny3, TinyZero>;
        using Erase0 = boost::mpl::erase<Tiny3, TinyIterator0>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<const long, char*>>::type::value));

        using TinyIterator1 = TinyIterator<Tiny3, TinyOne>;
        using Erase1 = boost::mpl::erase<Tiny3, TinyIterator1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<unsigned short&, char*>>::type::value));

        using TinyIterator2 = TinyIterator<Tiny3, TinyTwo>;

        using Erase2 = boost::mpl::erase<Tiny3, TinyIterator2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<unsigned short&, const long>>::type::value));
    }

    {
        using TinyIterator0 = TinyIterator<Tiny2, TinyZero>;
        using Erase0 = boost::mpl::erase<Tiny2, TinyIterator0>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<char*>>::type::value));

        using TinyIterator1 = TinyIterator<Tiny2, TinyOne>;
        using Erase1 = boost::mpl::erase<Tiny2, TinyIterator1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<const long>>::type::value));

        using TinyIterator2 = TinyIterator<Tiny2, TinyTwo>;

#if 0  // 这里应该产生编译错误。

		using Invalid = boost::mpl::erase<Tiny2, TinyIterator2>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny1, TinyZero>;
        using Erase0 = boost::mpl::erase<Tiny1, TinyIterator0>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<>>::type::value));

        using TinyIterator1 = TinyIterator<Tiny1, TinyOne>;

#if 0  // 这里应该产生编译错误。

		using Invalid = boost::mpl::erase<Tiny1, TinyIterator1>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny0, TinyZero>;

#if 0  // 这里应该产生编译错误。

		using Invalid = boost::mpl::erase<Tiny0, TinyIterator0>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny3, TinyZero>;
        using TinyIterator1 = TinyIterator<Tiny3, TinyOne>;
        using TinyIterator2 = TinyIterator<Tiny3, TinyTwo>;
        using TinyIterator3 = TinyIterator<Tiny3, TinyThree>;

#if 0  // 这里应该产生编译错误。

        using Invalid0 = boost::mpl::erase<Tiny3, TinyIterator0, TinyIterator0>::type;

#endif  // 0

        using Erase0 = boost::mpl::erase<Tiny3, TinyIterator0, TinyIterator1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<const long, char*>>::type::value));

        using Erase1 = boost::mpl::erase<Tiny3, TinyIterator0, TinyIterator2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<char*>>::type::value));

        using Erase2 = boost::mpl::erase<Tiny3, TinyIterator0, TinyIterator3>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。

        using Invalid1 = boost::mpl::erase<Tiny3, TinyIterator1, TinyIterator1>::type;

#endif  // 0

        using Erase3 = boost::mpl::erase<Tiny3, TinyIterator1, TinyIterator2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase3, Tiny<unsigned short&, char*>>::type::value));

        using Erase4 = boost::mpl::erase<Tiny3, TinyIterator1, TinyIterator3>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase4, Tiny<unsigned short&>>::type::value));

#if 0  // 这里应该产生编译错误。

        using Invalid2 = boost::mpl::erase<Tiny3, TinyIterator2, TinyIterator2>::type;

#endif  // 0

        using Erase5 = boost::mpl::erase<Tiny3, TinyIterator2, TinyIterator3>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase5, Tiny<unsigned short&, const long>>::type::value));
    }

    {
        using TinyIterator0 = TinyIterator<Tiny2, TinyZero>;
        using TinyIterator1 = TinyIterator<Tiny2, TinyOne>;
        using TinyIterator2 = TinyIterator<Tiny2, TinyTwo>;
        using TinyIterator3 = TinyIterator<Tiny2, TinyThree>;

        using Erase0 = boost::mpl::erase<Tiny2, TinyIterator0, TinyIterator1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase0, Tiny<char*>>::type::value));

        using Erase1 = boost::mpl::erase<Tiny2, TinyIterator0, TinyIterator2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase1, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。

		using Invalid0 = boost::mpl::erase<Tiny3, TinyIterator0, TinyIterator3>::type;

#endif  // 0

        using Erase2 = boost::mpl::erase<Tiny2, TinyIterator1, TinyIterator2>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<Erase2, Tiny<const long>>::type::value));

#if 0  // 这里应该产生编译错误。

        using Invalid1 = boost::mpl::erase<Tiny2, TinyIterator1, TinyIterator3>::type;

#endif  // 0

#if 0  // 这里应该产生编译错误。	

		using Invalid2 = boost::mpl::erase<Tiny2, TinyIterator2, TinyIterator3>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny1, TinyZero>;
        using TinyIterator1 = TinyIterator<Tiny1, TinyOne>;
        using TinyIterator2 = TinyIterator<Tiny1, TinyTwo>;

        using e0 = boost::mpl::erase<Tiny1, TinyIterator0, TinyIterator1>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<e0, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。

        using Invalid0 = boost::mpl::erase<Tiny1, TinyIterator0, TinyIterator2>::type;

#endif  // 0

#if 0  // 这里应该产生编译错误。

        using Invalid1 = boost::mpl::erase<Tiny1, TinyIterator1, TinyIterator2>::type;

#endif  // 0
    }

    {
        using TinyIterator0 = TinyIterator<Tiny0, TinyZero>;
        using TinyIterator1 = TinyIterator<Tiny0, TinyOne>;

#if 0  // 这里应该产生编译错误。

        using Invalid = boost::mpl::erase<Tiny0, TinyIterator0, TinyIterator1>::type;

#endif  // 0
    }
}
