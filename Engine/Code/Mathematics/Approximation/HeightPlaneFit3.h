///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <vector>

namespace Mathematics
{
    // 最小二乘平面的拟合到(x,y,f(x,y))通过使用在z方向距离测量数据。
    // 由此产生的平面由z = A*x + B*y + C表示。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightPlaneFit3 final
    {
    public:
        using ClassType = HeightPlaneFit3<Real>;

        using Vector3 = Vector3<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector3>;

    public:
        explicit HeightPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // 如果在线性系统中的3×3系数矩阵的定义A，B，C是（几乎）单数的这个情况下，
        // 返回值是“假”。
        NODISCARD bool IsFit3Success() const noexcept;

        NODISCARD Real GetCoeffA() const;
        NODISCARD Real GetCoeffB() const;
        NODISCARD Real GetCoeffC() const;

    private:
        void Calculate(const Points& points);

    private:
        Real coeffA;
        Real coeffB;
        Real coeffC;
        bool isFit3Success;
    };

    using HeightPlaneFit3F = HeightPlaneFit3<float>;
    using HeightPlaneFit3D = HeightPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
