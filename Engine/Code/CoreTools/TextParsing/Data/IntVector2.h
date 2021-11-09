///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/18 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR2_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR2_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IntVector2 final
    {
    public:
        using ClassType = IntVector2;

    public:
        constexpr IntVector2() noexcept
            : IntVector2{ 0, 0 }
        {
        }

        constexpr IntVector2(int x, int y) noexcept
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