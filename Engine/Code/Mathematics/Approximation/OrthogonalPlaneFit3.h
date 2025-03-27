///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
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

        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector3>;

    public:
        explicit OrthogonalPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Plane3 GetPlane3() const noexcept;

    private:
        NODISCARD static Plane3 Calculate(const Points& points);

    private:
        Plane3 plane3;
    };

    using OrthogonalPlaneFit3F = OrthogonalPlaneFit3<float>;
    using OrthogonalPlaneFit3D = OrthogonalPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
