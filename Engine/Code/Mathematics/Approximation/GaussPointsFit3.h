///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:18)

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
    class GaussPointsFit3 final
    {
    public:
        using ClassType = GaussPointsFit3<Real>;
        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using PointsType = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit GaussPointsFit3(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Box3 GetBox3() const noexcept;

    private:
        NODISCARD static Box3 Calculate(const PointsType& points);

    private:
        Box3 box;
    };

    using GaussPointsFit3F = GaussPointsFit3<float>;
    using GaussPointsFit3D = GaussPointsFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
