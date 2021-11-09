///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/18 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR3_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR3_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IntVector3 final
    {
    public:
        using ClassType = IntVector3;

    public:
        constexpr IntVector3() noexcept
            : IntVector3{ 0, 0, 0 }
        {
        }

        constexpr IntVector3(int x, int y, int z) noexcept
            : x{ x }, y{ y }, z{ z }
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

    private:
        int x;
        int y;
        int z;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_INT_VECTOR3_H