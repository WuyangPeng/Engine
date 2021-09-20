///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/07 23:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_TYPE_TRAITS_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_TYPE_TRAITS_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        struct AlwaysInt
        {
            typedef int type;
        };

        struct TrueType
        {
        };
        struct FalseType
        {
        };

        template <class T>
        struct TypeTraits  // assume nothing
        {
            typedef FalseType has_trivial_default_constructor;
            typedef FalseType has_trivial_copy_constructor;
            typedef FalseType has_trivial_assignment_operator;
            typedef FalseType has_trivial_destructor;
            typedef FalseType is_POD_type;
        };

        template <>
        struct TypeTraits<char>  // specialization for char
        {
            typedef TrueType has_trivial_default_constructor;
            typedef TrueType has_trivial_copy_constructor;
            typedef TrueType has_trivial_assignment_operator;
            typedef TrueType has_trivial_destructor;
            typedef TrueType is_POD_type;
        };
        /* more specializations follow... */
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_TYPE_TRAITS_H
