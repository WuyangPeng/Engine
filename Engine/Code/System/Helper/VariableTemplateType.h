///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/16 21:38)

#ifndef SYSTEM_HELPER_VARIABLE_TEMPLATE_TYPE_H
#define SYSTEM_HELPER_VARIABLE_TEMPLATE_TYPE_H

#include <tuple>
#include <type_traits>

namespace System
{
    template <typename... Types>
    struct VariableTemplateType final
    {
        using ClassType = VariableTemplateType<Types...>;

        static constexpr auto count = sizeof...(Types);

        template <size_t index>
        struct Element
        {
            static_assert(index < count);

            using Type = typename std::tuple_element<index, std::tuple<Types...>>::type;
        };
    };

    template <size_t index, typename... Types>
    struct IsScalarImpl final
    {
        using ClassType = IsScalarImpl<index, Types...>;

        static_assert(std::is_scalar<VariableTemplateType<Types...>::Element<index>::Type>::value);

        using Type = typename IsScalarImpl<index - 1, Types...>::Type;
    };

    template <typename... Types>
    struct IsScalarImpl<0, Types...> final
    {
        using ClassType = IsScalarImpl<0, Types...>;

        static_assert(std::is_scalar<VariableTemplateType<Types...>::Element<0>::Type>::value);

        using Type = std::true_type;
    };

    template <typename... Types>
    struct IsScalar final
    {
        using ClassType = IsScalar<Types...>;

        using Type = typename IsScalarImpl<VariableTemplateType<Types...>::count - 1, Types...>::Type;
    };
}

#endif  // SYSTEM_HELPER_VARIABLE_TEMPLATE_TYPE_H
