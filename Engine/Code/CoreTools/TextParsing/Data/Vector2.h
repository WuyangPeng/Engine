///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/25 19:20)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR2_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR2_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class Vector2 final
    {
    public:
        using ClassType = Vector2;

    public:
        constexpr Vector2() noexcept
            : Vector2{ 0.0, 0.0 }
        {
        }

        constexpr Vector2(const double x, const double y) noexcept
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