/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:28)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR3_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR3_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class IntVector3 final
    {
    public:
        using ClassType = IntVector3;

    public:
        constexpr IntVector3() noexcept
            : IntVector3{ 0, 0, 0 }
        {
        }

        constexpr IntVector3(const int x, const int y, const int z) noexcept
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