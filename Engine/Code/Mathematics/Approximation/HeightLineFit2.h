///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 15:08)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
    // ��С����ƽ����ϵ��ߵ�(x,f(x)) ͨ��ʹ����y�����ϵľ���������ݡ�
    // �ɴ˲��������� y = A * x + B.
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightLineFit2 final
    {
    public:
        using ClassType = HeightLineFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector2D>;

    public:
        explicit HeightLineFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // ����ڶ���A��B�ǣ��������������Է�����2x2��ϵ������
        // ����ֵ��false��
        // ����������£�����A��B���׳��쳣��
        [[nodiscard]] bool IsFit2Success() const noexcept;

        [[nodiscard]] Real GetCoeffA() const;
        [[nodiscard]] Real GetCoeffB() const;

    private:
        void Calculate(const Points& points);

    private:
        Real m_CoeffA;
        Real m_CoeffB;
        bool m_IsFit2Success;
    };

    using FloatHeightLineFit2 = HeightLineFit2<float>;
    using DoubleHeightLineFit2 = HeightLineFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
