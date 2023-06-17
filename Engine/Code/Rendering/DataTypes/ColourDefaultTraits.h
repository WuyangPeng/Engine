///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H
#define RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H

#include <type_traits>

namespace Rendering
{
    template <typename T, typename Enable = void>
    struct ColourDefaultTraits;

    template <typename T>
    struct ColourDefaultTraits<T, typename std::enable_if<std::is_floating_point_v<T>>::type>
    {
        static constexpr auto minValue = 0;
        static constexpr auto maxValue = 1;
    };

    template <typename T>
    struct ColourDefaultTraits<T, typename std::enable_if<std::is_integral_v<T>>::type>
    {
        static_assert(!std::is_same_v<char, T>, "T must not char type!");
        static_assert(!std::is_same_v<int8_t, T>, "T must not int8_t type!");

        static constexpr auto minValue = 0;
        static constexpr auto maxValue = 0xFF;
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H
