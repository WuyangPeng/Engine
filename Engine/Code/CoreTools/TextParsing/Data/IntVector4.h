///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/25 19:20)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR4_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR4_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class IntVector4 final
    {
    public:
        using ClassType = IntVector4;

    public:
        constexpr IntVector4() noexcept
            : IntVector4{ 0, 0, 0, 0 }
        {
        }

        constexpr IntVector4(const int x, const int y, const int z, const int w) noexcept
            : x{ x }, y{ y }, z{ z }, w{ w }
        {
        }

        NODISCARD constexpr int GetX() const noexcept
        {
            return x;
        }

        NODISCARD constexpr int GetY() const noexcept
        {
            return y;
        }

        NODISCARD constexpr int GetZ() const noexcept
        {
            return z;
        }

        NODISCARD constexpr int GetW() const noexcept
        {
            return w;
        }

    private:
        int x;
        int y;
        int z;
        int w;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_INT_VECTOR4_H