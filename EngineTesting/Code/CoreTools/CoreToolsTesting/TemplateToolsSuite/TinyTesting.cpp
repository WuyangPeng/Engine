// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 16:08)

#include "TinyTesting.h"
#include "Detail/TinyTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Tiny.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TinyTesting)

void CoreTools::TinyTesting ::MainTest()
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

void CoreTools::TinyTesting ::InitTest() noexcept
{
    using FirstTiny = Tiny<>;
    using SeconTiny = Tiny<char>;
    using ThirdTiny = Tiny<char, long>;
    using FourthTiny = Tiny<char, char, int>;

    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<FirstTiny>::value, ==, 0);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<SeconTiny>::value, ==, 1);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<ThirdTiny>::value, ==, 2);
    BOOST_MPL_ASSERT_RELATION(boost::mpl::size<FourthTiny>::value, ==, 3);

    BOOST_MPL_ASSERT((boost::mpl::empty<FirstTiny>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<SeconTiny>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<ThirdTiny>));
    BOOST_MPL_ASSERT_NOT((boost::mpl::empty<FourthTiny>));

    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<SeconTiny>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<SeconTiny>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<ThirdTiny>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<ThirdTiny>::type, long>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<FourthTiny>::type, char>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<FourthTiny>::type, int>));
}

void CoreTools::TinyTesting ::PushBackTest() noexcept
{
    using FirstTiny = Tiny<>;

    using SecondTiny = boost::mpl::push_back<FirstTiny, int>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<SecondTiny>::type, int>));

    using ThirdTiny = boost::mpl::push_front<SecondTiny, char>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<ThirdTiny>::type, int>));
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::front<ThirdTiny>::type, char>));

    using FourthTiny = boost::mpl::push_back<ThirdTiny, long>::type;
    BOOST_MPL_ASSERT((boost::is_same<boost::mpl::back<FourthTiny>::type, long>));

    [[maybe_unused]] TinyTest<FirstTiny>::type firstTiny;
    [[maybe_unused]] TinyTest<SecondTiny>::type secondTiny;
    [[maybe_unused]] TinyTest<ThirdTiny>::type thirdTiny;
    [[maybe_unused]] TinyTest<FourthTiny>::type fourthTiny;

    using FifthTiny = boost::mpl::push_back<FirstTiny, char>::type;
    using SixthTiny = boost::mpl::push_back<FifthTiny, int>::type;
    using SeventhTiny = boost::mpl::push_back<ThirdTiny, long>::type;

#if 0  // 这里应该产生编译错误。
	using InvalidTiny = boost::mpl::push_back<FourthTiny, int>::type;
#endif  // 0

    BOOST_STATIC_ASSERT((boost::mpl::equal<SixthTiny, ThirdTiny>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<SeventhTiny, FourthTiny>::type::value));
}

void CoreTools::TinyTesting ::ClearTest() noexcept
{
    using FirstTiny = Tiny<>;
    using SecondTiny = Tiny<unsigned short, double&, bool>;

    [[maybe_unused]] TinyTest<FirstTiny>::type firstTiny;
    [[maybe_unused]] TinyTest<SecondTiny>::type secondTiny;

    using Clean = boost::mpl::clear<SecondTiny>::type;
    BOOST_STATIC_ASSERT((boost::mpl::equal<FirstTiny, Clean>::type::value));
}

void CoreTools::TinyTesting ::PushFrontTest() noexcept
{
    using FirstTiny = Tiny<>;
    using SecondTiny = Tiny<char*>;
    using ThirdTiny = Tiny<const long, char*>;
    using FourthTiny = Tiny<unsigned short&, const long, char*>;

    [[maybe_unused]] TinyTest<FirstTiny>::type firstTiny;
    [[maybe_unused]] TinyTest<SecondTiny>::type secondTiny;
    [[maybe_unused]] TinyTest<ThirdTiny>::type thirdTiny;
    [[maybe_unused]] TinyTest<FourthTiny>::type fourthTiny;

    using FifthTiny = boost::mpl::push_front<FirstTiny, char*>::type;
    using SixthTiny = boost::mpl::push_front<SecondTiny, const long>::type;
    using SeventhTiny = boost::mpl::push_front<ThirdTiny, unsigned short&>::type;

#if 0  // 这里应该产生编译错误。
	using InvalidTiny = boost::mpl::push_front<FourthTiny, int>::type;
#endif  // 0

    BOOST_STATIC_ASSERT((boost::mpl::equal<FifthTiny, SecondTiny>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<SixthTiny, ThirdTiny>::type::value));
    BOOST_STATIC_ASSERT((boost::mpl::equal<SeventhTiny, FourthTiny>::type::value));
}

void CoreTools::TinyTesting ::EmptyTest() noexcept
{
    using FirstTiny = Tiny<>;

    [[maybe_unused]] TinyTest<FirstTiny>::type firstTiny;

#if 0  // 这里应该产生编译错误。
	using FirstInvalidType = boost::mpl::at<FirstTiny, TinyZero>::type;
#endif  // 0

    using Beg = boost::mpl::begin<FirstTiny>::type;

#if 0  // 这里应该产生编译错误。
	using SecondInvalidType = boost::mpl::next<Beg>::type;
#endif  // 0

#if 0  // 这里应该产生编译错误。
	using ThirdInvalidType = boost::mpl::deref<Beg>::type;
#endif  // 0

    using End = boost::mpl::end<FirstTiny>::type;

#if 0  // 这里应该产生编译错误。
	using FourthInvalidType = boost::mpl::prior<End>::type;
#endif  // 0

#if 0  // 这里应该产生编译错误。
	using FifthInvalidType = boost::mpl::advance<Beg, TinyOne>::type;
#endif  // 0

#if 0  // 这里应该产生编译错误。
	using SixthInvalidType = boost::mpl::advance<End, boost::mpl::int_<-1>>::type;
#endif  // 0
}

void CoreTools::TinyTesting ::InteratorTest() noexcept
{
    using FirstTiny = Tiny<>;
    using SecondTiny = Tiny<int>;
    using ThirdTiny = Tiny<char*, const long>;
    using FourthTiny = Tiny<unsigned short&, const long, char*>;

    [[maybe_unused]] TinyTest<FirstTiny>::type tiny1;
    [[maybe_unused]] TinyTest<SecondTiny>::type tiny2;
    [[maybe_unused]] TinyTest<ThirdTiny>::type tiny3;
    [[maybe_unused]] TinyTest<FourthTiny>::type tiny4;

    {
        using FirstTinyIterator = TinyIterator<FirstTiny, TinyZero>;
        using SecondTinyIterator = boost::mpl::insert<FirstTiny, FirstTinyIterator, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondTinyIterator, Tiny<long>>::type::value));

        using ThirdTinyIterator = TinyIterator<SecondTinyIterator, TinyZero>;
        using FourthTinyIterator = boost::mpl::insert<SecondTinyIterator, ThirdTinyIterator, int>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FourthTinyIterator, Tiny<int, long>>::type::value));

        using FifthTinyIterator = TinyIterator<FourthTinyIterator, TinyZero>;
        using SixthTinyIterator = boost::mpl::insert<FourthTinyIterator, FifthTinyIterator, char>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SixthTinyIterator, Tiny<char, int, long>>::type::value));

        using SeventhTinyIterator = TinyIterator<SixthTinyIterator, TinyZero>;

#if 0  // 这里应该产生编译错误。		
		using InvalidTinyIterator = boost::mpl::insert<SixthTinyIterator, SeventhTinyIterator, bool>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<SecondTiny, TinyOne>;
        using SecondTinyIterator = boost::mpl::insert<SecondTiny, FirstTinyIterator, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondTinyIterator, Tiny<int, long>>::type::value));

        using ThirdTinyIterator = TinyIterator<SecondTinyIterator, TinyOne>;
        using FourthTinyIterator = boost::mpl::insert<SecondTinyIterator, ThirdTinyIterator, char>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FourthTinyIterator, Tiny<int, char, long>>::type::value));
        using FifthTinyIterator = TinyIterator<FourthTinyIterator, TinyOne>;

#if 0  // 这里应该产生编译错误。				
		using InvalidTinyIterator = boost::mpl::insert<FourthTinyIterator, FifthTinyIterator, bool>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<ThirdTiny, TinyTwo>;
        using SecondTinyIterator = boost::mpl::insert<ThirdTiny, FirstTinyIterator, long>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondTinyIterator, Tiny<char*, const long, long>>::type::value));
        using ThirdTinyIterator = TinyIterator<SecondTinyIterator, TinyTwo>;

#if 0  // 这里应该产生编译错误。			
		using InvalidTinyIterator = boost::mpl::insert<SecondTinyIterator, ThirdTinyIterator, char>::type;
#endif  // 0
    }

    {
        using FifthTiny = boost::mpl::pop_front<FourthTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FifthTiny, Tiny<const long, char*>>::type::value));
        using SixthTiny = boost::mpl::pop_front<ThirdTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SixthTiny, Tiny<const long>>::type::value));
        using SeventhTiny = boost::mpl::pop_front<SecondTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SeventhTiny, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。			
		using InvalidType = boost::mpl::pop_front<FirstTiny>::type;
#endif  // 0
    }

    {
        using FifthTiny = boost::mpl::pop_back<FourthTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FifthTiny, Tiny<unsigned short&, const long>>::type::value));
        using SixthTiny = boost::mpl::pop_back<ThirdTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SixthTiny, Tiny<char*>>::type::value));
        using SevnthTiny = boost::mpl::pop_back<SecondTiny>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SevnthTiny, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。	
		using InvalidType = boost::mpl::pop_back<SevnthTiny>::type;
#endif  // 0
    }
}

void CoreTools::TinyTesting ::EraseTest() noexcept
{
    using FirstTiny = Tiny<>;
    using SecondTiny = Tiny<char*>;
    using ThirdTiny = Tiny<const long, char*>;
    using FourthTiny = Tiny<unsigned short&, const long, char*>;

    [[maybe_unused]] TinyTest<FirstTiny>::type tiny1;
    [[maybe_unused]] TinyTest<SecondTiny>::type tiny2;
    [[maybe_unused]] TinyTest<ThirdTiny>::type tiny3;
    [[maybe_unused]] TinyTest<FourthTiny>::type tiny4;

    {
        using FirstTinyIterator = TinyIterator<FourthTiny, TinyZero>;
        using FirstErase = boost::mpl::erase<FourthTiny, FirstTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FirstErase, Tiny<const long, char*>>::type::value));

        using SecondTinyIterator = TinyIterator<FourthTiny, TinyOne>;
        using SecondErase = boost::mpl::erase<FourthTiny, SecondTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondErase, Tiny<unsigned short&, char*>>::type::value));

        using ThirdTinyIterator = TinyIterator<FourthTiny, TinyTwo>;

        using ThirdErase = boost::mpl::erase<FourthTiny, ThirdTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<ThirdErase, Tiny<unsigned short&, const long>>::type::value));
    }

    {
        using FirstTinyIterator = TinyIterator<ThirdTiny, TinyZero>;
        using FirstErase = boost::mpl::erase<ThirdTiny, FirstTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FirstErase, Tiny<char*>>::type::value));

        using SecondTinyIterator = TinyIterator<ThirdTiny, TinyOne>;
        using ThirdErase = boost::mpl::erase<ThirdTiny, SecondTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<ThirdErase, Tiny<const long>>::type::value));

        using ThirdTinyIterator = TinyIterator<ThirdTiny, TinyTwo>;

#if 0  // 这里应该产生编译错误。
		using Invalid = boost::mpl::erase<ThirdTiny, ThirdTinyIterator>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<SecondTiny, TinyZero>;
        using FirstErase = boost::mpl::erase<SecondTiny, FirstTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FirstErase, Tiny<>>::type::value));

        using SecondTinyIterator = TinyIterator<SecondTiny, TinyOne>;

#if 0  // 这里应该产生编译错误。
		using Invalid = boost::mpl::erase<SecondTiny, SecondTinyIterator>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<FirstTiny, TinyZero>;

#if 0  // 这里应该产生编译错误。
		using Invalid = boost::mpl::erase<FirstTiny, FirstTinyIterator>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<FourthTiny, TinyZero>;
        using SecondTinyIterator = TinyIterator<FourthTiny, TinyOne>;
        using ThirdTinyIterator = TinyIterator<FourthTiny, TinyTwo>;
        using FourthTinyIterator = TinyIterator<FourthTiny, TinyThree>;

#if 0  // 这里应该产生编译错误。
		using FirstInvalid = boost::mpl::erase<FourthTiny, FirstTinyIterator, FirstTinyIterator>::type;
#endif  // 0

        using FirstErase = boost::mpl::erase<FourthTiny, FirstTinyIterator, SecondTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FirstErase, Tiny<const long, char*>>::type::value));

        using SecondErase = boost::mpl::erase<FourthTiny, FirstTinyIterator, ThirdTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondErase, Tiny<char*>>::type::value));

        using ThirdErase = boost::mpl::erase<FourthTiny, FirstTinyIterator, FourthTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<ThirdErase, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。
		using SecondInvalid = boost::mpl::erase<FourthTiny, SecondTinyIterator, SecondTinyIterator>::type;
#endif  // 0

        using FourthErase = boost::mpl::erase<FourthTiny, SecondTinyIterator, ThirdTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FourthErase, Tiny<unsigned short&, char*>>::type::value));

        using FifthErase = boost::mpl::erase<FourthTiny, SecondTinyIterator, FourthTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FifthErase, Tiny<unsigned short&>>::type::value));

#if 0  // 这里应该产生编译错误。
		using ThirdInvalid = boost::mpl::erase<FourthTiny, ThirdTinyIterator, ThirdTinyIterator>::type;
#endif  // 0

        using SixthErase = boost::mpl::erase<FourthTiny, ThirdTinyIterator, FourthTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SixthErase, Tiny<unsigned short&, const long>>::type::value));
    }

    {
        using FirstTinyIterator = TinyIterator<ThirdTiny, TinyZero>;
        using SecondTinyIterator = TinyIterator<ThirdTiny, TinyOne>;
        using ThirdTinyIterator = TinyIterator<ThirdTiny, TinyTwo>;
        using FourthTinyIterator = TinyIterator<ThirdTiny, TinyThree>;

        using FirstErase = boost::mpl::erase<ThirdTiny, FirstTinyIterator, SecondTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<FirstErase, Tiny<char*>>::type::value));

        using SecondErase = boost::mpl::erase<ThirdTiny, FirstTinyIterator, ThirdTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<SecondErase, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。
		using FirstInvalid = boost::mpl::erase<ThirdTiny, FirstTinyIterator, FourthTinyIterator>::type;
#endif  // 0

        using ThirdErase = boost::mpl::erase<ThirdTiny, SecondTinyIterator, ThirdTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<ThirdErase, Tiny<const long>>::type::value));

#if 0  // 这里应该产生编译错误。
		using SecondInvalid = boost::mpl::erase<ThirdTiny, SecondTinyIterator, FourthTinyIterator>::type;
#endif  // 0

#if 0  // 这里应该产生编译错误。		
		using ThirdInvalid = boost::mpl::erase<ThirdTiny, ThirdTinyIterator, FourthTinyIterator>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<SecondTiny, TinyZero>;
        using SecondTinyIterator = TinyIterator<SecondTiny, TinyOne>;
        using ThirdTinyIterator = TinyIterator<SecondTiny, TinyTwo>;

        using e0 = boost::mpl::erase<SecondTiny, FirstTinyIterator, SecondTinyIterator>::type;
        BOOST_STATIC_ASSERT((boost::mpl::equal<e0, Tiny<>>::type::value));

#if 0  // 这里应该产生编译错误。	
		using FirstInvalid = boost::mpl::erase<SecondTiny, FirstTinyIterator, ThirdTinyIterator>::type;
#endif  // 0

#if 0  // 这里应该产生编译错误。	
		using SecondInvalid = boost::mpl::erase<SecondTiny, SecondTinyIterator, ThirdTinyIterator>::type;
#endif  // 0
    }

    {
        using FirstTinyIterator = TinyIterator<FirstTiny, TinyZero>;
        using SecondTinyIterator = TinyIterator<FirstTiny, TinyOne>;

#if 0  // 这里应该产生编译错误。	
		using Invalid = boost::mpl::erase<FirstTiny, FirstTinyIterator, SecondTinyIterator>::type;
#endif  // 0
    }
}
#include STSTEM_WARNING_POP