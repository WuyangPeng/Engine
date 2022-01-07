///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 21:31)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR2_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR2_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Vector2 final
    {
    public:
        using ClassType = Vector2;

    public:
        constexpr Vector2() noexcept
            : Vector2{ 0.0, 0.0 }
        {
        }

        constexpr Vector2(double x, double y) noexcept
            : x{ x }, y{ y }
        {
        }

        NODISCARD constexpr double GetX() const noexcept
        {
            return x;
        }

        NODISCARD constexpr double GetY() const noexcept
        {
            return y;
        }

    private:
        double x;
        double y;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR2_H