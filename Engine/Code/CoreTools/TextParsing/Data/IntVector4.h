///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/18 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_INT_VECTOR4_H
#define CORE_TOOLS_TEXT_PARSING_INT_VECTOR4_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IntVector4 final
    {
    public:
        using ClassType = IntVector4;

    public:
        constexpr IntVector4() noexcept
            : IntVector4{ 0, 0, 0, 0 }
        {
        }

        constexpr IntVector4(int x, int y, int z, int w) noexcept
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