///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 15:55)

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
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit OrthogonalLineFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Line3 GetLine3() const noexcept;

    private:
        [[nodiscard]] static Line3 Calculate(const Points& points);

    private:
        Line3 m_Line;
    };

    using FloatOrthogonalLineFit3 = OrthogonalLineFit3<float>;
    using DoubleOrthogonalLineFit3 = OrthogonalLineFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
