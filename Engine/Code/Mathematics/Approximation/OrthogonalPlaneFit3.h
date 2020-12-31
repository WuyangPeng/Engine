///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 16:02)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Plane3.h"

#include <vector>

namespace Mathematics
{
    // 最小二乘方拟合的平面(x,y,z) 的数据，通过使用距离测量正交拟合平面。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalPlaneFit3 final
    {
    public:
        using ClassType = OrthogonalPlaneFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit OrthogonalPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Plane3 GetPlane3() const noexcept;

    private:
        [[nodiscard]] static Plane3 Calculate(const Points& points);

    private:
        Plane3 m_Plane3;
    };

    using FloatOrthogonalPlaneFit3 = OrthogonalPlaneFit3<float>;
    using DoubleOrthogonalPlaneFit3 = OrthogonalPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
