///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Objects3D/Plane3.h"

#include <vector>

namespace Mathematics
{
    // ��С���˷���ϵ�ƽ��(x,y,z) �����ݣ�ͨ��ʹ�þ�������������ƽ�档
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
