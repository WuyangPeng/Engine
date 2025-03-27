///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:25)

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

        using Vector2Type = Vector2<Real>;
        using Box2Type = Box2<Real>;
        using MathType = Math<Real>;
        using PointsType = std::vector<Vector2Type>;

    public:
        explicit GaussPointsFit2(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Box2Type GetBox2() const noexcept;

    private:
        NODISCARD static Box2Type Calculate(const PointsType& points);

    private:
        Box2Type box;
    };

    using GaussPointsFit2F = GaussPointsFit2<float>;
    using GaussPointsFit2D = GaussPointsFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
