///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:26)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

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

        using Vector3 = Vector3<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector3>;

    public:
        explicit HeightPlaneFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        // ���������ϵͳ�е�3��3ϵ������Ķ���A��B��C�ǣ��������������������£�
        // ����ֵ�ǡ��١���
        NODISCARD bool IsFit3Success() const noexcept;

        NODISCARD Real GetCoeffA() const;
        NODISCARD Real GetCoeffB() const;
        NODISCARD Real GetCoeffC() const;

    private:
        void Calculate(const Points& points);

    private:
        Real coeffA;
        Real coeffB;
        Real coeffC;
        bool isFit3Success;
    };

    using HeightPlaneFit3F = HeightPlaneFit3<float>;
    using HeightPlaneFit3D = HeightPlaneFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
