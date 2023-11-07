///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

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

        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit GreatCircleFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetNormal() noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3 normal;
    };

    using GreatCircleFit3F = GreatCircleFit3<float>;
    using GreatCircleFit3D = GreatCircleFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
