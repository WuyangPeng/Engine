///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
    // ��С���η�����ߵ�(x,y,z)�����ݣ�ͨ��ʹ�þ����������������ߡ�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit2 final
    {
    public:
        using ClassType = OrthogonalLineFit2<Real>;

        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector2>;

    public:
        explicit OrthogonalLineFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line2 GetLine2() const noexcept;

    private:
        NODISCARD static Line2 Calculate(const Points& points);

    private:
        Line2 line;
    };

    using OrthogonalLineFit2F = OrthogonalLineFit2<float>;
    using OrthogonalLineFit2D = OrthogonalLineFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
