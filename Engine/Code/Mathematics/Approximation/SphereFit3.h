///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:52)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    // ��һ������С���������
    // ��������Ĵ����ѳ���maxIterations������һ�����ԡ��������ӵ��������������
    // ���initialCenterIsAverage����Ϊ���桱��
    // �����������ĵĳ�ʼ�²������ݵ��ƽ��ֵ��
    // ������ݵ���һ������ǵ�Ⱥ����SphereFit3�������ٶȺ�����
    // ���initialCenterIsAverage����Ϊ���١���
    // �������ĵĳ�ʼֵ�²�ʹ��һ��������η��̣�
    // ��ʾһ�������ϵ������С���˷������㡣
    // ��������������Ѹ��������
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SphereFit3 final
    {
    public:
        using ClassType = SphereFit3<Real>;

        using Vector3 = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Points = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        SphereFit3(const Points& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Sphere3 GetSphere() const noexcept;

    private:
        void Calculate(const Points& points, int maxIterations, bool initialCenterIsAverage);
        NODISCARD Vector3 GetAveragePoint(const Points& points);
        void Iteration(const Points& points, const Vector3& average);

    private:
        Sphere3 sphere;
    };

    using SphereFit3F = SphereFit3<float>;
    using SphereFit3D = SphereFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
