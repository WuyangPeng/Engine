///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 15:04)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Line3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cylinder3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Cylinder3<Real>;
        using Math = Math<Real>;
        using Line3 = Line3<Real>;

    public:
        // 缸体轴线是一条线。缸体的原点被选择为线原点。
        // 缸体壁是在距离轴线Real单元。无限的缸体有无限的高度。
        // 一个有限缸体有中点C在线的起点和具有有限的高度H
        // 线段为有限圆柱体端点C-(H/2)*D 和 C+(H/2)*D，其中D是线的单位长度方向。
        Cylinder3(const Line3& axis, Real radius, Real height) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetAxis() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetHeight() const noexcept;

    private:
        Line3 axis;
        Real radius;
        Real height;
    };

    using Cylinder3F = Cylinder3<float>;
    using Cylinder3D = Cylinder3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CYLINDER3_H
