///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

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

        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector2>;

    public:
        explicit HeightLineFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // ����ڶ���A��B�ǣ��������������Է�����2x2��ϵ������
        // ����ֵ��false��
        // ����������£�����A��B���׳��쳣��
        NODISCARD bool IsFit2Success() const noexcept;

        NODISCARD Real GetCoeffA() const;
        NODISCARD Real GetCoeffB() const;

    private:
        void Calculate(const Points& points);

    private:
        Real coeffA;
        Real coeffB;
        bool isFit2Success;
    };

    using HeightLineFit2F = HeightLineFit2<float>;
    using HeightLineFit2D = HeightLineFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
