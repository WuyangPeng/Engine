/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_CIRCLE3_H
#define MATHEMATICS_OBJECTS_3D_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Circle3<Real>;

        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using Vector3Tools = Vector3Tools<Real>;

    public:
        // 含有该圆的平面是Dot(N,X-C) = 0，其中X是在平面上的任意点。
        // 向量U，V和N形成正交右手坐标系集合。
        // （矩阵[U V N]是正交的，具有行列式1）。
        // 在平面内的圆周参数为X = C + Real * (cos(t) * U + sin(t) * V)，
        // 其中t是在[-pi,pi)的角度。

        // U 是输入向量 'direction0', V 是输入向量 'direction1,
        // 和 N 是输入向量 'normal'.
        Circle3(const Vector3& center,
                const Vector3& direction0,
                const Vector3& direction1,
                const Vector3& normal,
                const Real radius,
                const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetDirection0() const noexcept;
        NODISCARD Vector3 GetDirection1() const noexcept;
        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        NODISCARD Circle3 GetMove(Real t, const Vector3& velocity) const;

    private:
        Vector3 center;
        Vector3 direction0;
        Vector3 direction1;
        Vector3 normal;
        Real radius;
        Real epsilon;
    };

    using Circle3F = Circle3<float>;
    using Circle3D = Circle3<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Circle3<Real>& circle);
}

#endif  // MATHEMATICS_OBJECTS_3D_CIRCLE3_H
