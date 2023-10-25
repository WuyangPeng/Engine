///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/25 19:20)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR4_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR4_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class Vector4 final
    {
    public:
        using ClassType = Vector4;

    public:
        constexpr Vector4() noexcept
            : Vector4{ 0.0, 0.0, 0.0, 0.0 }
        {
        }

        constexpr Vector4(const double x, const double y, const double z, const double w) noexcept
            : x{ x }, y{ y }, z{ z }, w{ w }
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

        NODISCARD constexpr double GetZ() const noexcept
        {
            return z;
        }

        NODISCARD constexpr double GetW() const noexcept
        {
            return w;
        }

    private:
        double x;
        double y;
        double z;
        double w;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR4_H