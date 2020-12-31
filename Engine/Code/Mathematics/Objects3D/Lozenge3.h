///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 17:44)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Lozenge3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Lozenge3<Real>;
        using Rectangle3 = Rectangle3<Real>;

    public:
        // 菱形是一组是等距的矩形的点，共同的距离称为半径。
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

    private:
        Rectangle3 m_Rectangle;
        Real m_Radius;
    };

    using FloatLozenge3 = Lozenge3<float>;
    using DoubleLozenge3 = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_LOZENGE3_H
