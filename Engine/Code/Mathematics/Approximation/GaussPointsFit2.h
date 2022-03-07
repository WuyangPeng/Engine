///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 13:57)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"

#include <vector>

namespace Mathematics
{
    // ��˹�ֲ���ϵ㡣�������ǵ��ƽ��ֵ����������Э������������������
    // ����չ��Э������������ֵ�Ͳ��Ե�����˳�򷵻ء�
    // �����洢��Box2<Real>������һ����һ�������С�
    template <typename Real>
    class GaussPointsFit2 final
    {
    public:
        using ClassType = GaussPointsFit2<Real>;
        using Vector2 = Vector2<Real>;
        using Box2 = Box2<Real>;
        using Math = Math<Real>;
        using PointsType = std::vector<Vector2>;

    public:
        explicit GaussPointsFit2(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Box2 GetBox2() const noexcept;

    private:
        NODISCARD static Box2 Calculate(const PointsType& points);

    private:
        Box2 box;
    };

    using GaussPointsFit2F = GaussPointsFit2<float>;
    using GaussPointsFit2D = GaussPointsFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
