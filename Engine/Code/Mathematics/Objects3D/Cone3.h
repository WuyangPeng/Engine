/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_CONE3_H
#define MATHEMATICS_OBJECTS_3D_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cone3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Cone3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;

    public:
        // 锐角锥体是Dot(A,X-V) = |X-V| cos(t)
        // 其中V是顶点，A为圆锥的轴的单位长度方向，
        // 并且T是圆锥角在0 < t < pi/2。
        // 圆锥内部的点定义为Dot(A,X-V) >= |X-V| cos(t)。
        // 由于cos(t) > 0，可避免计算平方根。
        // 固体锥是由不等式定义为 Dot(A,X-V)^2 >= Dot(X-V,X-V) cos(t)^2。
        // 这是一个无限的，单面锥。
        //
        // 锥体可以由平面截断垂直于它在从顶点的高度h的轴
        // （从顶点至平面的交点与轴的距离）。
        // 无限锥体h = 无穷大。
        // 有限锥体有一个底盘上的平面和无限锥体之间交叉。
        // 底盘的半径r为r = h*tan(t)。

        // axis必须是单位长度和角度必须在(0,pi/2)。
        // 对于无限锥，设置“height”为Math<Real>::sm_MaxReal
        Cone3(const Vector3Type& vertex,
              const Vector3Type& axis,
              const Real angle,
              const Real height,
              const Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // axis必须是单位长度。
        // 一对(cosAngle,sinAngle)必须严格在平面的第一象限，以保证锥角为(0,pi/2)
        // 对于无限锥，设置“height”为Math<Real>::sm_MaxReal
        Cone3(const Real cosAngle,
              const Real sinAngle,
              const Real height,
              const Vector3Type& vertex,
              const Vector3Type& axis,
              const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetVertex() const noexcept;
        NODISCARD Vector3Type GetAxis() const noexcept;
        NODISCARD Real GetCosAngle() const noexcept;
        NODISCARD Real GetSinAngle() const noexcept;
        NODISCARD Real GetHeight() const noexcept;

    private:
        Vector3Type vertex;
        Vector3Type axis;
        Real cosAngle;
        Real sinAngle;
        Real height;

        Real epsilon;
    };

    using Cone3F = Cone3<float>;
    using Cone3D = Cone3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONE3_H
