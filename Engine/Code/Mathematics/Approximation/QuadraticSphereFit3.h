///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:52)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <vector>

namespace Mathematics
{
    // 如果你觉得你的点几乎是球体的，使用这个。
    // 球的形式C'[0]+C'[1]*X+C'[2]*Y+C'[3]*Z+C'[4]*(X^2+Y^2+Z^2)，
    // 其中Length(C') = 1
    // 该函数返回C = (C'[0]/C'[4],C'[1]/C'[4],C'[2]/C'[4],C'[3]/C'[4])，
    // 所以拟合球是 C[0]+C[1]*X+C[2]*Y+C[3]*Z+X^2+Y^2+Z^2。
    // 该中心是(xc,yc,zc) = -0.5*(C[1],C[2],C[3])和
    // 半径为rad = sqrt(xc*xc+yc*yc+zc*zc-C[0])。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticSphereFit3 final
    {
    public:
        using ClassType = QuadraticSphereFit3<Real>;

        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit QuadraticSphereFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static int eigenSystemSize = 5;

    private:
        Vector3 center;
        Real radius;
        Real eigenValue;
    };

    using QuadraticSphereFit3F = QuadraticSphereFit3<float>;
    using QuadraticSphereFit3D = QuadraticSphereFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
