///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 15:50)

#ifndef MATHEMATICS_OBJECTS3D_CIRCLE3_H
#define MATHEMATICS_OBJECTS3D_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // 含有该圆的平面是Dot(N,X-C) = 0，其中X是在平面上的任意点。
        // 向量U，V和N形成正交右手坐标系集合。
        // （矩阵[U V N]是正交的，具有行列式1）。
        // 在平面内的圆周参数为X = C + Real * (cos(t) * U + sin(t) * V)，
        // 其中t是在[-pi,pi)的角度。

        // U 是输入向量 'direction0', V 是输入向量 'direction1,
        // 和 N 是输入向量 'normal'.
        Circle3(const Vector3D& center, const Vector3D& direction0, const Vector3D& direction1,
                const Vector3D& normal, const Real radius, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetDirection0() const noexcept;
        [[nodiscard]] const Vector3D GetDirection1() const noexcept;
        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

        [[nodiscard]] const Circle3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        Vector3D m_Center;
        Vector3D m_Direction0;
        Vector3D m_Direction1;
        Vector3D m_Normal;
        Real m_Radius;
        Real m_Epsilon;
    };

    using FloatCircle3 = Circle3<float>;
    using DoubleCircle3 = Circle3<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Circle3<Real>& circle);
}

#endif  // MATHEMATICS_OBJECTS3D_CIRCLE3_H
