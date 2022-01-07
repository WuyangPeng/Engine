///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_TINY_H
#define CORE_TOOLS_TEMPLATE_TOOLS_TINY_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/mpl/and.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/size.hpp>

namespace CoreTools
{
    using TinyZero = boost::mpl::int_<0>;
    using TinyOne = boost::mpl::int_<1>;
    using TinyTwo = boost::mpl::int_<2>;
    using TinyThree = boost::mpl::int_<3>;

    struct TinyNone
    {
    };

    struct TinyTag
    {
    };

    template <typename T0 = TinyNone, typename T1 = TinyNone, typename T2 = TinyNone>
    struct Tiny
    {
        using ClassTag = TinyTag;
        using ClassType = Tiny<T0, T1, T2>;
        using ClassT0 = T0;
        using ClassT1 = T1;
        using ClassT2 = T2;

        using tag = ClassTag;
        using type = ClassType;
    };

    template <typename Tiny, typename Pos>
    struct TinyIterator
    {
        using ClassType = TinyIterator<Tiny, Pos>;
        using category = boost::mpl::random_access_iterator_tag;
    };

    template <typename T, int N>
    struct TinyAt;

    template <typename T>
    struct TinyAt<T, 0>
    {
        using Tiny = T;
        using ClassType = TinyAt<Tiny, 0>;
        using type = typename Tiny::ClassT0;
    };

    template <typename T>
    struct TinyAt<T, 1>
    {
        using Tiny = T;
        using ClassType = TinyAt<Tiny, 1>;
        using type = typename Tiny::ClassT1;
    };

    template <typename T>
    struct TinyAt<T, 2>
    {
        using Tiny = T;
        using ClassType = TinyAt<Tiny, 2>;
        using type = typename Tiny::ClassT2;
    };

    template <typename T0, typename T1, typename T2>
    struct TinySize : TinyThree
    {
        using ClassType = TinySize<T0, T1, T2>;
        using ParentType = TinyThree;
    };

    template <typename T0, typename T1>
    struct TinySize<T0, T1, TinyNone> : TinyTwo
    {
        using ClassType = TinySize<T0, T1, TinyNone>;
        using ParentType = TinyTwo;
    };

    template <typename T0>
    struct TinySize<T0, TinyNone, TinyNone> : TinyOne
    {
        using ClassType = TinySize<T0, TinyNone, TinyNone>;
        using ParentType = TinyOne;
    };

    template <>
    struct TinySize<TinyNone, TinyNone, TinyNone> : TinyZero
    {
        using ClassType = TinySize<TinyNone, TinyNone, TinyNone>;
        using ParentType = TinyZero;
    };

    template <typename TinyType, typename T, int N>
    struct TinyPushBack;

    template <typename TinyType, typename T>
    struct TinyPushBack<TinyType, T, 0> : Tiny<T>
    {
        using ClassType = TinyPushBack<TinyType, T, 0>;
        using ParentType = Tiny<T>;
    };

    template <typename TinyType, typename T>
    struct TinyPushBack<TinyType, T, 1> : Tiny<typename TinyType::ClassT0, T>
    {
        using ClassType = TinyPushBack<TinyType, T, 1>;
        using ParentType = Tiny<typename TinyType::ClassT0, T>;
    };

    template <typename TinyType, typename T>
    struct TinyPushBack<TinyType, T, 2> : Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1, T>
    {
        using ClassType = TinyPushBack<TinyType, T, 2>;
        using ParentType = Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1, T>;
    };

    template <typename T>
    struct CheckNotFull
    {
        using Tiny = T;
        using ClassType = CheckNotFull<Tiny>;

        static_assert(boost::mpl::less<typename boost::mpl::size<Tiny>::type, TinyThree>::value, "Check not full is error.");
    };

    template <typename T>
    struct CheckNotEmpty
    {
        using Tiny = T;
        using ClassType = CheckNotEmpty<Tiny>;

        static_assert(boost::mpl::greater<typename boost::mpl::size<Tiny>::type, TinyZero>::value, "Check not empty is error.");
    };

    template <typename TinyType, typename T, int N>
    struct TinyInsert;

    template <typename TinyType, typename T>
    struct TinyInsert<TinyType, T, 0> : Tiny<T, typename TinyType::ClassT0, typename TinyType::ClassT1>, CheckNotFull<TinyType>
    {
        using ClassType = TinyInsert<TinyType, T, 0>;
        using ParentType = Tiny<T, typename TinyType::ClassT0, typename TinyType::ClassT1>;
    };

    template <typename TinyType, typename T>
    struct TinyInsert<TinyType, T, 1> : Tiny<typename TinyType::ClassT0, T, typename TinyType::ClassT1>, CheckNotFull<TinyType>
    {
        using ClassType = TinyInsert<TinyType, T, 1>;
        using ParentType = Tiny<typename TinyType::ClassT0, T, typename TinyType::ClassT1>;
    };

    template <typename TinyType, typename T>
    struct TinyInsert<TinyType, T, 2> : Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1, T>, CheckNotFull<TinyType>
    {
        using ClassType = TinyInsert<TinyType, T, 2>;
        using ParentType = Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1, T>;
    };

    template <typename T0, typename T1, typename T2>
    struct TinyPopFront : Tiny<T1, T2>
    {
        using ClassType = TinyPopFront<T0, T1, T2>;
        using ParentType = Tiny<T1, T2>;
    };

    template <typename T0, typename T1, typename T2>
    struct TinyPopBack : Tiny<T0, T1>
    {
        using ClassType = TinyPopBack<T0, T1, T2>;
        using ParentType = Tiny<T0, T1>;
    };

    template <typename T0, typename T1>
    struct TinyPopBack<T0, T1, TinyNone> : Tiny<T0>
    {
        using ClassType = TinyPopBack<T0, T1, TinyNone>;
        using ParentType = Tiny<T0>;
    };

    template <typename T0>
    struct TinyPopBack<T0, TinyNone, TinyNone> : Tiny<>
    {
        using ClassType = TinyPopBack<T0, TinyNone, TinyNone>;
        using ParentType = Tiny<>;
    };

    template <typename TinyType, int N>
    struct TinyErase;

    template <typename TinyType>
    struct TinyErase<TinyType, 0> : Tiny<typename TinyType::ClassT1, typename TinyType::ClassT2>
    {
        using ClassType = TinyErase<TinyType, 0>;
        using ParentType = Tiny<typename TinyType::ClassT1, typename TinyType::ClassT2>;
    };

    template <typename TinyType>
    struct TinyErase<TinyType, 1> : Tiny<typename TinyType::ClassT0, typename TinyType::ClassT2>
    {
        using ClassType = TinyErase<TinyType, 1>;
        using ParentType = Tiny<typename TinyType::ClassT0, typename TinyType::ClassT2>;
    };

    template <typename TinyType>
    struct TinyErase<TinyType, 2> : Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1>
    {
        using ClassType = TinyErase<TinyType, 2>;
        using ParentType = Tiny<typename TinyType::ClassT0, typename TinyType::ClassT1>;
    };

    template <typename Tiny, typename Pos>
    struct TinyHasItem : boost::mpl::eval_if<boost::mpl::and_<boost::mpl::greater<typename boost::mpl::size<Tiny>::type, Pos>,
                                                              boost::mpl::greater<Pos, boost::mpl::prior<TinyZero>::type>>,
                                             boost::mpl::true_, boost::mpl::false_>
    {
        using ClassType = TinyHasItem<Tiny, Pos>;
    };

    template <typename Tiny, int F, int L>
    struct TinyEraseRange;

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 0, 1> : boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyZero>>
    {
        using ClassType = TinyEraseRange<Tiny, 0, 1>;
    };

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 0, 2>
    {
        using ClassType = TinyEraseRange<Tiny, 0, 2>;
        using TempEraseType = typename boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyOne>>::type;
        using type = typename boost::mpl::erase<TempEraseType, TinyIterator<TempEraseType, TinyZero>>::type;
    };

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 0, 3>
    {
        using ClassType = TinyEraseRange<Tiny, 0, 3>;
        using FirstTempEraseType = typename boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyTwo>>::type;
        using SecondTempEraseType = typename boost::mpl::erase<FirstTempEraseType, TinyIterator<FirstTempEraseType, TinyOne>>::type;
        using type = typename boost::mpl::erase<SecondTempEraseType, TinyIterator<SecondTempEraseType, TinyZero>>::type;
    };

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 1, 2> : boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyOne>>
    {
        using ClassType = TinyEraseRange<Tiny, 1, 2>;
    };

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 1, 3>
    {
        using ClassType = TinyEraseRange<Tiny, 1, 3>;
        using TempEraseType = typename boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyTwo>>::type;
        using type = typename boost::mpl::erase<TempEraseType, TinyIterator<TempEraseType, TinyOne>>::type;
    };

    template <typename Tiny>
    struct TinyEraseRange<Tiny, 2, 3> : boost::mpl::erase<Tiny, TinyIterator<Tiny, TinyTwo>>
    {
        using ClassType = TinyEraseRange<Tiny, 2, 3>;
    };
}

namespace boost
{
    namespace mpl
    {
        template <typename Tiny, typename Pos>
        struct next<CoreTools::TinyIterator<Tiny, Pos>>
        {
            using ClassType = next<CoreTools::TinyIterator<Tiny, Pos>>;
            static_assert(boost::mpl::greater<typename size<Tiny>::type, Pos>::value, "next is error.");

            using type = CoreTools::TinyIterator<Tiny, typename boost::mpl::next<Pos>::type>;
        };

        template <typename Tiny, typename Pos>
        struct prior<CoreTools::TinyIterator<Tiny, Pos>>
        {
            using ClassType = prior<CoreTools::TinyIterator<Tiny, Pos>>;
            static_assert(boost::mpl::greater<Pos, CoreTools::TinyZero>::value, "prior is error.");

            using type = CoreTools::TinyIterator<Tiny, typename boost::mpl::prior<Pos>::type>;
        };

        template <>
        struct at_impl<CoreTools::TinyTag>
        {
            template <typename Tiny, typename N>
            struct apply : CoreTools::TinyAt<Tiny, N::value>
            {
                using ClassType = apply<Tiny, N>;
                static_assert(boost::mpl::greater<typename size<Tiny>::type, N>::value, "at_impl is error.");
            };
        };

        template <typename Tiny, typename Pos>
        struct deref<CoreTools::TinyIterator<Tiny, Pos>> : at<Tiny, Pos>
        {
            using ClassType = deref<CoreTools::TinyIterator<Tiny, Pos>>;
            using ParentType = at<Tiny, Pos>;
        };

        template <typename Tiny, typename Pos, typename N>
        struct advance<CoreTools::TinyIterator<Tiny, Pos>, N>
        {
            using NewPos = typename boost::mpl::plus<Pos, N>::type;
            using ClassType = advance<CoreTools::TinyIterator<Tiny, Pos>>;

            static_assert(boost::mpl::greater<typename size<Tiny>::type, NewPos>::value, "advance is error.");

            static_assert(boost::mpl::greater<NewPos, boost::mpl::int_<-1>>::value, "advance is error.");

            using type = CoreTools::TinyIterator<Tiny, NewPos>;
        };

        template <typename Tiny, typename Pos1, typename Pos2>
        struct advance<CoreTools::TinyIterator<Tiny, Pos1>, CoreTools::TinyIterator<Tiny, Pos2>> : boost::mpl::minus<Pos2, Pos1>
        {
            using ClassType = advance<CoreTools::TinyIterator<Tiny, Pos1>, CoreTools::TinyIterator<Tiny, Pos2>>;
        };

        template <>
        struct begin_impl<CoreTools::TinyTag>
        {
            template <typename Tiny>
            struct apply
            {
                using type = CoreTools::TinyIterator<Tiny, CoreTools::TinyZero>;
            };
        };

        template <>
        struct end_impl<CoreTools::TinyTag>
        {
            template <typename Tiny>
            struct apply
            {
                using ClassType = apply<Tiny>;
                using type = CoreTools::TinyIterator<Tiny, typename CoreTools::TinySize<typename Tiny::ClassT0, typename Tiny::ClassT1, typename Tiny::ClassT2>::type>;
            };
        };

        template <>
        struct size_impl<CoreTools::TinyTag>
        {
            template <typename Tiny>
            struct apply : CoreTools::TinySize<typename Tiny::ClassT0, typename Tiny::ClassT1, typename Tiny::ClassT2>
            {
                using ClassType = apply<Tiny>;
            };
        };

        template <>
        struct clear_impl<CoreTools::TinyTag>
        {
            template <typename TinyType>
            struct apply : CoreTools::Tiny<>
            {
                using ClassType = apply<Tiny>;
            };
        };

        template <>
        struct push_front_impl<CoreTools::TinyTag>
        {
            template <typename TinyType, typename T>
            struct apply : CoreTools::Tiny<T, typename TinyType::ClassT0, typename TinyType::ClassT1>
            {
                using ClassType = apply<TinyType, T>;
                using ParentType = CoreTools::Tiny<T, typename TinyType::ClassT0, typename TinyType::ClassT1>;
                static_assert(boost::mpl::less<typename size<TinyType>::type, CoreTools::TinyThree>::value, "push_front_impl is error");
            };
        };

        template <>
        struct push_back_impl<CoreTools::TinyTag>
        {
            template <typename TinyType, typename T>
            struct apply : CoreTools::TinyInsert<TinyType, T, size<TinyType>::value>
            {
                using ClassType = apply<TinyType, T>;
                using ParentType = CoreTools::TinyInsert<TinyType, T, size<TinyType>::value>;
            };
        };

        template <>
        struct insert_impl<CoreTools::TinyTag>
        {
            template <typename TinyType, typename Pos, typename T>
            struct apply;

            template <typename TinyType, typename Pos, typename T>
            struct apply<TinyType, CoreTools::TinyIterator<TinyType, Pos>, T> : CoreTools::TinyInsert<TinyType, T, Pos::value>
            {
                using ClassType = apply<TinyType, CoreTools::TinyIterator<TinyType, Pos>, T>;
                using ParentType = CoreTools::TinyInsert<TinyType, T, Pos::value>;
            };
        };

        template <>
        struct pop_front_impl<CoreTools::TinyTag>
        {
            template <typename T>
            struct apply : CoreTools::CheckNotEmpty<T>,
                           CoreTools::TinyPopFront<typename T::ClassT0, typename T::ClassT1, typename T::ClassT2>
            {
                using ClassType = apply<T>;
                using ParentType = CoreTools::TinyPopFront<typename T::ClassT0, typename T::ClassT1, typename T::ClassT2>;
            };
        };

        template <>
        struct pop_back_impl<CoreTools::TinyTag>
        {
            template <typename T>
            struct apply : CoreTools::CheckNotEmpty<T>,
                           CoreTools::TinyPopBack<typename T::ClassT0, typename T::ClassT1, typename T::ClassT2>
            {
                using ClassType = apply<T>;
                using ParentType = CoreTools::TinyPopBack<typename T::ClassT0, typename T::ClassT1, typename T::ClassT2>;
            };
        };

        template <>
        struct erase_impl<CoreTools::TinyTag>
        {
            template <typename TinyType, typename First, typename Last>
            struct apply;

            template <typename TinyType, typename First, typename Last>
            struct apply<TinyType, CoreTools::TinyIterator<TinyType, First>, Last> : CoreTools::TinyErase<TinyType, First::value>
            {
                using ClassType = apply<TinyType, CoreTools::TinyIterator<TinyType, First>, Last>;
                using ParentType = CoreTools::TinyErase<TinyType, First::value>;
                static_assert(CoreTools::TinyHasItem<TinyType, First>::type::value, "erase_impl is error.");
            };

            template <typename TinyType, typename First, typename Last>
            struct apply<TinyType, CoreTools::TinyIterator<TinyType, First>, CoreTools::TinyIterator<TinyType, Last>> : CoreTools::TinyEraseRange<TinyType, First::value, Last::value>
            {
                using ClassType = apply<TinyType, CoreTools::TinyIterator<TinyType, First>, CoreTools::TinyIterator<TinyType, Last>>;
                using ParentType = CoreTools::TinyEraseRange<TinyType, First::value, Last::value>;
            };
        };
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_TINY_H
