///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:45)

#ifndef MATHEMATICS_OBJECTS_3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS_3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Lozenge3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Lozenge3<Real>;
        using Rectangle3 = Rectangle3<Real>;

    public:
        // 菱形是一组是等距的矩形的点，共同的距离称为半径。
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Rectangle3 GetRectangle() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

    private:
        Rectangle3 rectangle;
        Real radius;
    };

    using Lozenge3F = Lozenge3<float>;
    using Lozenge3D = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_LOZENGE3_H
