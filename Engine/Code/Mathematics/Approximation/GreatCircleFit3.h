///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 14:51)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // ��С����ʹ�þ���������������һ����Բ����λ�������� (x,y,z) �����ش�Բ������������Ĵ�Բ��
    // ����points[]�ǵ�λ���ȡ����ص�ֵ�ǵ�λ���ȣ���������N��
    // ��ϵĴ�Բ����ΪDot(N,X) = 0������X�Ǵ�Բһ����λ����ʸ����
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatCircleFit3 final
    {
    public:
        using ClassType = GreatCircleFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit GreatCircleFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetNormal() noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3D m_Normal;
    };

    using FloatGreatCircleFit3 = GreatCircleFit3<float>;
    using DoubleGreatCircleFit3 = GreatCircleFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
