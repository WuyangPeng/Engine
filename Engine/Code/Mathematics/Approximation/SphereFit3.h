///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 11:09)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
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
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        SphereFit3(const Points& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

    private:
        void Calculate(const Points& points, int maxIterations, bool initialCenterIsAverage);
        [[nodiscard]] const Vector3D GetAveragePoint(const Points& points);
        void Iteration(const Points& points, const Vector3D& average);

    private:
        Sphere3 m_Sphere;
    };

    using FloatSphereFit3 = SphereFit3<float>;
    using DoubleSphereFit3 = SphereFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
