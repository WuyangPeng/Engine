///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 11:34)

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
