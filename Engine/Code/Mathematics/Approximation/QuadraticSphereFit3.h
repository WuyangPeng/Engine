///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 11:09)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // ����������ĵ㼸��������ģ�ʹ�������
    // �����ʽC'[0]+C'[1]*X+C'[2]*Y+C'[3]*Z+C'[4]*(X^2+Y^2+Z^2)��
    // ����Length(C') = 1
    // �ú�������C = (C'[0]/C'[4],C'[1]/C'[4],C'[2]/C'[4],C'[3]/C'[4])��
    // ����������� C[0]+C[1]*X+C[2]*Y+C[3]*Z+X^2+Y^2+Z^2��
    // ��������(xc,yc,zc) = -0.5*(C[1],C[2],C[3])��
    // �뾶Ϊrad = sqrt(xc*xc+yc*yc+zc*zc-C[0])��
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuadraticSphereFit3 final
    {
    public:
        using ClassType = QuadraticSphereFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit QuadraticSphereFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;
        [[nodiscard]] Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static int sm_EigenSystemSize = 5;

    private:
        Vector3D m_Center;
        Real m_Radius;
        Real m_EigenValue;
    };

    using FloatQuadraticSphereFit3 = QuadraticSphereFit3<float>;
    using DoubleQuadraticSphereFit3 = QuadraticSphereFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
