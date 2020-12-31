///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 13:39)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GaussPointsFit2 final
    {
    public:
        using ClassType = GaussPointsFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Box2 = Box2<Real>;
        using Math = Math<Real>;
        using PointsType = std::vector<Vector2D>;

    public:
        explicit GaussPointsFit2(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Box2 GetBox2() const noexcept;

    private:
        [[nodiscard]] static Box2 Calculate(const PointsType& points);

    private:
        Box2 m_Box;
    };

    using FloatGaussPointsFit2 = GaussPointsFit2<float>;
    using DoubleGaussPointsFit2 = GaussPointsFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
