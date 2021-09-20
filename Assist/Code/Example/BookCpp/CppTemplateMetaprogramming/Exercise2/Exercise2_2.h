///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/14 23:15)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_2_H
#define CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_2_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingCustomAssertMacro.h"

#include <boost/core/addressof.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <cassert>

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)

        template <class Target, class Source>
        Target PolymorphicDowncast(Source* x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncast转换失败");
            return static_cast<Target>(x);
        }

        template <class Target, class Source>
        Target PolymorphicDowncast(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            using TargetPointerType = typename boost::remove_reference<Target>::type*;
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<TargetPointerType>(&x) == &x, "PolymorphicDowncast转换失败");
            return *static_cast<TargetPointerType>(&x);
        }

#include STSTEM_WARNING_POP

        struct CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE ATest
        {
            ATest() noexcept = default;
            virtual ~ATest() noexcept = default;
            ATest(const ATest& rhs) noexcept = default;
            ATest& operator=(const ATest& rhs) noexcept = default;
            ATest(ATest&& rhs) noexcept = default;
            ATest& operator=(ATest&& rhs) noexcept = default;
        };

        struct CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE B : ATest
        {
        };

        CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE void Test() noexcept(g_CppTemplateMetaprogrammingAssert < 0);

        // boost库的解决方案

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)

        template <class Target, class Source>
        inline Target PolymorphicDowncast1(Source* x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncast1转换失败");  // detect logic error
            return static_cast<Target>(x);
        }

        template <class Target, class Source>
        typename boost::enable_if_c<boost::is_reference<Target>::value, Target>::type PolymorphicDowncast1(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            typedef typename boost::remove_reference<Target>::type* TargetPointerType;
            return *PolymorphicDowncast1<TargetPointerType>(boost::addressof(x));
        }

        // Ariel Badichi的解决方案
        template <typename Target, typename Source>
        Target PolymorphicDowncast2(Source* x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncast2转换失败");
            return static_cast<Target>(x);
        }

        template <typename Target, typename Source>
        Target PolymorphicDowncast2(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            typedef typename boost::remove_reference<Target>::type noref;
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<noref*>(&x) == &x, "PolymorphicDowncast2转换失败");
            return static_cast<Target>(x);
        }

#include STSTEM_WARNING_POP

        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE BTest
        {
        public:
            BTest() noexcept = default;
            virtual ~BTest() noexcept = default;
            BTest(const BTest& rhs) noexcept = default;
            BTest& operator=(const BTest& rhs) noexcept = default;
            BTest(BTest&& rhs) noexcept = default;
            BTest& operator=(BTest&& rhs) noexcept = default;

            virtual void Fn() noexcept;
        };

        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE D : public BTest
        {
        };

        // 一个解决方案
        template <typename Derived, typename Base>
        Derived PolymorphicDowncast3(Base& base)
        {
            return *boost::polymorphic_downcast<typename boost::remove_reference<Derived>::type*>(&base);
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)

        // Daboe的解决方案
        // 
        // 这个解决方案存在问题，ATest&传入PolymorphicDowncast4，S被推导为ATest。
        template <class T, class S, bool is_ref>
        struct PolymorphicDowncastImpl
        {
            static inline T DoIt(S s) noexcept
            {
                assert(dynamic_cast<T>(s) == s);
                return static_cast<T>(s);
            }
        };
        template <class T, class S>
        struct PolymorphicDowncastImpl<T, S, true>
        {
            typedef typename boost::remove_reference<T>::type Noref;
            static inline T DoIt(S s) noexcept
            {
                assert(dynamic_cast<Noref*>(&s) == &s);
                return static_cast<T>(s);
            }
        };

#include STSTEM_WARNING_POP

        template <class T, class S>
        T PolymorphicDowncast4(S s) noexcept
        {
            static constexpr bool isRef = boost::is_reference<T>::value;
            return PolymorphicDowncastImpl<T, S, isRef>::DoIt(s);
        }
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_EXERCISE2_EXERCISE2_2_H
