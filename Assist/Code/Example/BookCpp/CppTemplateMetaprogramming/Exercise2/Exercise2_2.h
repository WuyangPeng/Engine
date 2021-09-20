///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/14 23:15)

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
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncastת��ʧ��");
            return static_cast<Target>(x);
        }

        template <class Target, class Source>
        Target PolymorphicDowncast(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            using TargetPointerType = typename boost::remove_reference<Target>::type*;
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<TargetPointerType>(&x) == &x, "PolymorphicDowncastת��ʧ��");
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

        // boost��Ľ������

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)

        template <class Target, class Source>
        inline Target PolymorphicDowncast1(Source* x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncast1ת��ʧ��");  // detect logic error
            return static_cast<Target>(x);
        }

        template <class Target, class Source>
        typename boost::enable_if_c<boost::is_reference<Target>::value, Target>::type PolymorphicDowncast1(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            typedef typename boost::remove_reference<Target>::type* TargetPointerType;
            return *PolymorphicDowncast1<TargetPointerType>(boost::addressof(x));
        }

        // Ariel Badichi�Ľ������
        template <typename Target, typename Source>
        Target PolymorphicDowncast2(Source* x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<Target>(x) == x, "PolymorphicDowncast2ת��ʧ��");
            return static_cast<Target>(x);
        }

        template <typename Target, typename Source>
        Target PolymorphicDowncast2(Source& x) noexcept(g_CppTemplateMetaprogrammingAssert < 0)
        {
            typedef typename boost::remove_reference<Target>::type noref;
            CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(dynamic_cast<noref*>(&x) == &x, "PolymorphicDowncast2ת��ʧ��");
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

        // һ���������
        template <typename Derived, typename Base>
        Derived PolymorphicDowncast3(Base& base)
        {
            return *boost::polymorphic_downcast<typename boost::remove_reference<Derived>::type*>(&base);
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)

        // Daboe�Ľ������
        // 
        // �����������������⣬ATest&����PolymorphicDowncast4��S���Ƶ�ΪATest��
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
