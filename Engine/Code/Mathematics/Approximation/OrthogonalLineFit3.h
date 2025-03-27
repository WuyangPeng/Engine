///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"

#include <vector>

namespace Mathematics
{
    // ��С���η�����ߵ�(x,y,z)�����ݣ�ͨ��ʹ�þ����������������ߡ�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE OrthogonalLineFit3 final
    {
    public:
        using ClassType = OrthogonalLineFit3<Real>;

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector3Type>;

    public:
        explicit OrthogonalLineFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3Type GetLine3() const noexcept;

    private:
        NODISCARD static Line3Type Calculate(const Points& points);

    private:
        Line3Type line;
    };

    using OrthogonalLineFit3F = OrthogonalLineFit3<float>;
    using OrthogonalLineFit3D = OrthogonalLineFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
