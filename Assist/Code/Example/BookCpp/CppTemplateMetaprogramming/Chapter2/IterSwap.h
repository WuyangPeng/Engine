///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/07 23:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITER_SWAP_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITER_SWAP_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <iterator>  // for iterator_traits
#include <utility>  // for swap

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        typedef int T;

        template <class ForwardIterator1, class ForwardIterator2>
        void IterSwap1(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
        {
            T tmp = *i1;
            *i1 = *i2;
            *i2 = tmp;
        }

        template <class ForwardIterator1, class ForwardIterator2>
        void IterSwap2(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
        {
            typename  // (see Language Note)
                ForwardIterator1::value_type tmp = *i1;
            *i1 = *i2;
            *i2 = tmp;
        }

        template <class I1, class I2>
        void IterSwap3(I1, I2) noexcept
        {
        }

        void F(int* p1, int* p2) noexcept;

        template <class Iterator>
        struct IteratorTraits;

        template <class ForwardIterator1, class ForwardIterator2>
        void IterSwap4(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
        {
            typename IteratorTraits<ForwardIterator1>::value_type tmp = *i1;
            *i1 = *i2;
            *i2 = tmp;
        }

        namespace Hector
        {
            struct hands_off
            {
            };
        }

        template <>
        struct IteratorTraits<Hector::hands_off>
        {
            typedef int value_type;
            /* four more typedefs... */
        };

        template <class T>
        struct IteratorTraits<T*>
        {
            typedef T value_type;
            typedef T& reference;
            /* ...four more typedefs */
        };

        template <class Iterator>
        struct IteratorTraits
        {
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::reference reference;
            /* ...four more typedefs */
        };

        void Foo(int* i1, int* i2) noexcept;

        template <class ForwardIterator1, class ForwardIterator2>
        void IterSwap5(ForwardIterator1 i1, ForwardIterator2 i2) noexcept
        {
            std::swap(*i1, *i2);
        }

        template <class T>
        void Swap1(T& x, T& y)
        {
            T tmp = x;
            x = y;
            y = tmp;
        }

        // Generalized (slow) version
        template <class ForwardIterator1, class ForwardIterator2>
        void IterSwap6(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
        {
            typename IteratorTraits<ForwardIterator1>::value_type
                tmp = *i1;
            *i1 = *i2;
            *i2 = tmp;
        }

        // A better match when the two iterators are the same type
        template <class ForwardIterator>
        void IterSwap6(ForwardIterator i1, ForwardIterator i2) noexcept
        {
            std::swap(*i1, *i2);  // sometimes faster
        }

        template <class T1, class T2>
        void Swap2(T1& a, T2& b)
        {
            T1 tmp = a;
            a = b;
            b = tmp;
        }

        struct Proxy
        {
            Proxy& operator=(bool x) noexcept;

            operator bool() const noexcept;

            unsigned char* bytes;
            size_t pos;
        };

        struct BitIterator
        {
            typedef bool value_type;
            typedef Proxy reference;
            /* more typedefs... */

            Proxy operator*() const;
            /* more operations... */
        };

        namespace Nonstd
        {
            template <bool use_swap>
            struct IterSwapImpl;  // see text

            template <class ForwardIterator1, class ForwardIterator2>
            void IterSwap(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
            {
                typedef IteratorTraits<ForwardIterator1> traits1;
                typedef typename traits1::value_type v1;
                typedef typename traits1::reference r1;

                typedef IteratorTraits<ForwardIterator2> traits2;
                typedef typename traits2::value_type v2;
                typedef typename traits2::reference r2;

                bool constexpr use_swap = boost::is_same<v1, v2>::value && boost::is_reference<r1>::value && boost::is_reference<r2>::value;

                IterSwapImpl<use_swap>::DoIt(i1, i2);
            }

            template <>
            struct IterSwapImpl<true>  // the "fast" one
            {
                template <class ForwardIterator1, class ForwardIterator2>
                static void DoIt(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
                {
                    std::swap(*i1, *i2);
                }
            };

            template <>
            struct IterSwapImpl<false>  // the one that always works
            {
                template <class ForwardIterator1, class ForwardIterator2>
                static void DoIt(ForwardIterator1 i1, ForwardIterator2 i2) noexcept(std::is_scalar_v<typename ForwardIterator1::value_type>&& std::is_scalar_v<typename ForwardIterator2::value_type>)
                {
                    typename IteratorTraits<ForwardIterator1>::value_type
                        tmp = *i1;
                    *i1 = *i2;
                    *i2 = tmp;
                }
            };

        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_ITER_SWAP_H
