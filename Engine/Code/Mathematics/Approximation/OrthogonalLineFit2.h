///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 15:47)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
    // 最小二次方拟合线到(x,y,z)的数据，通过使用距离测量正交建议的线。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit2 final
    {
    public:
        using ClassType = OrthogonalLineFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector2D>;

    public:
        explicit OrthogonalLineFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Line2 GetLine2() const noexcept;

    private:
        [[nodiscard]] static Line2 Calculate(const Points& points);

    private:
        Line2 m_Line;
    };

    using FloatOrthogonalLineFit2 = OrthogonalLineFit2<float>;
    using DoubleOrthogonalLineFit2 = OrthogonalLineFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
