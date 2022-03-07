///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 13:52)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"

#include <vector>

namespace Mathematics
{
    // 最小二次方拟合线到(x,y,z)的数据，通过使用距离测量正交建议的线。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit3 final
    {
    public:
        using ClassType = OrthogonalLineFit3<Real>;
        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3>;

    public:
        explicit OrthogonalLineFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetLine3() const noexcept;

    private:
        NODISCARD static Line3 Calculate(const Points& points);

    private:
        Line3 line;
    };

    using OrthogonalLineFit3F = OrthogonalLineFit3<float>;
    using OrthogonalLineFit3D = OrthogonalLineFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
