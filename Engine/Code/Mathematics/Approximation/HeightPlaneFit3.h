///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 15:33)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // ��С����ƽ�����ϵ�(x,y,f(x,y))ͨ��ʹ����z�������������ݡ�
    // �ɴ˲�����ƽ����z = A*x + B*y + C��ʾ��
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HeightPlaneFit3 final
    {
    public:
        using ClassType = HeightPlaneFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit HeightPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // ���������ϵͳ�е�3��3ϵ������Ķ���A��B��C�ǣ��������������������£�
        // ����ֵ�ǡ��١���
        [[nodiscard]] bool IsFit3Success() const noexcept;

        [[nodiscard]] Real GetCoeffA() const;
        [[nodiscard]] Real GetCoeffB() const;
        [[nodiscard]] Real GetCoeffC() const;

    private:
        void Calculate(const Points& points);

    private:
        Real m_CoeffA;
        Real m_CoeffB;
        Real m_CoeffC;
        bool m_IsFit3Success;
    };

    using FloatHeightPlaneFit3 = HeightPlaneFit3<float>;
    using DoubleHeightPlaneFit3 = HeightPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
