/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:59)

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

        template <size_t Index>
        requires(Index < count)
        struct Element
        {
            using Type = std::tuple_element_t<Index, std::tuple<Types...>>;
        };
    };

    template <size_t Index, typename... Types>
    requires(std::is_scalar_v<typename VariableTemplateType<Types...>::template Element<Index>::Type>)
    struct IsScalarImpl final
    {
        using ClassType = IsScalarImpl<Index, Types...>;

        using Type = typename IsScalarImpl<Index - 1, Types...>::Type;
    };

    template <typename... Types>
    requires(std::is_scalar_v<typename VariableTemplateType<Types...>::template Element<0>::Type>)
    struct IsScalarImpl<0, Types...> final
    {
        using ClassType = IsScalarImpl<0, Types...>;

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
