///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:24)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

#include <vector>

namespace Mathematics
{
    // ����������ĵ㼸����Բ�εģ�ʹ�������
    // Բ����ʽC'[0]+C'[1]*X+C'[2]*Y+C'[3]*(X^2+Y^2)��
    // ����Length(C') = 1
    // �ú�������C = (C'[0]/C'[3],C'[1]/C'[3],C'[2]/C'[3])��
    // �������Բ��C[0]+C[1]*X+C[2]*Y+X^2+Y^2��
    // ��������(xc,yc) = -0.5*(C[1],C[2])��
    // �뾶Ϊr = sqrt(xc*xc+yc*yc-C[0])��
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticCircleFit2 final
    {
    public:
        using ClassType = QuadraticCircleFit2<Real>;
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector2>;

    public:
        explicit QuadraticCircleFit2(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static auto eigenSystemSize = 4;

    private:
        Vector2 center;
        Real radius;
        Real eigenValue;
    };

    using QuadraticCircleFit2F = QuadraticCircleFit2<float>;
    using QuadraticCircleFit2D = QuadraticCircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
