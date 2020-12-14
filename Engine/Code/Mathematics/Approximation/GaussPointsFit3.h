///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 14:03)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"

#include <vector>

namespace Mathematics
{
    // ��˹�ֲ���ϵ㡣�������ǵ��ƽ��ֵ����������Э������������������
    // ����չ��Э������������ֵ�Ͳ��Ե�����˳�򷵻ء�
    // �����洢��Box3<Real>������һ����һ�������С�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GaussPointsFit3 final
    {
    public:
        using ClassType = GaussPointsFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using PointsType = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit GaussPointsFit3(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Box3 GetBox3() const noexcept;

    private:
        [[nodiscard]] static Box3 Calculate(const PointsType& points);

    private:
        Box3 m_Box;
    };

    using FloatGaussPointsFit3 = GaussPointsFit3<float>;
    using DoubleGaussPointsFit3d = GaussPointsFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
