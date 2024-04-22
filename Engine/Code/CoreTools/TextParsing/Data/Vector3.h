/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR3_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR3_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class Vector3 final
    {
    public:
        using ClassType = Vector3;

    public:
        constexpr Vector3() noexcept
            : Vector3{ 0.0, 0.0, 0.0 }
        {
        }

        constexpr Vector3(const double x, const double y, const double z) noexcept
            : x{ x }, y{ y }, z{ z }
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

    private:
        double x;
        double y;
        double z;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VECTOR3_H