///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 15:33)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

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
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit HeightPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // 如果在线性系统中的3×3系数矩阵的定义A，B，C是（几乎）单数的这个情况下，
        // 返回值是“假”。
        [[nodiscard]] bool IsFit3Success() const noexcept;

        [[nodiscard]] Real GetCoeffA() const;
        [[nodiscard]] Real GetCoeffB() const;
        [[nodiscard]] Real GetCoeffC() const;

    private:
        void Calculate(const Points& points);

    private:
        Real m_CoeffA;
        Real m_CoeffB;
        Real m_CoeffC;
        bool m_IsFit3Success;
    };

    using FloatHeightPlaneFit3 = HeightPlaneFit3<float>;
    using DoubleHeightPlaneFit3 = HeightPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
