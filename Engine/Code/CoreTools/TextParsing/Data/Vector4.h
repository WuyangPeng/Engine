///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/18 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_VECTOR4_H
#define CORE_TOOLS_TEXT_PARSING_VECTOR4_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Vector4 final
    {
    public:
        using ClassType = Vector4;

    public:
        constexpr Vector4() noexcept
            : Vector4{ 0.0, 0.0, 0.0, 0.0 }
        {
        }

        constexpr Vector4(double x, double y, double z, double w) noexcept
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