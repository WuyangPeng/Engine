/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:28)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR2_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR2_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class IntVector2 final
    {
    public:
        using ClassType = IntVector2;

    public:
        constexpr IntVector2() noexcept
            : IntVector2{ 0, 0 }
        {
        }

        constexpr IntVector2(const int x, const int y) noexcept
            : x{ x }, y{ y }
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

    private:
        int x;
        int y;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_INT_VECTOR2_H