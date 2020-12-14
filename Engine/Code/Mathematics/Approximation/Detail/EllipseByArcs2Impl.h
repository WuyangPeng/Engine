///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/02 16:31)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    // ��ԲΪ(x/a)^2 + (y/b)^2 = 1��
    // �����ڵ�һ�����еĲ���(x >= 0 and y >= 0)���ơ�
    // ����numArcs >= 2 �Ļ������Ӧ������������
    // ��Բ��(a,0) �� (0,b)�ļ�Ȩƽ��ֵ�С�
    // ���ص������������numArcs+1��Ԫ�غ�
    // ��������Բ�ĺͰ뾶ÿ��������numArcԪ�ء�
    // m_Points[i]��m_Points[i+1]������Ļ�
    // ��������m_Center[i]�Ͱ뾶��m_Radius[i]��

    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE EllipseByArcs2Impl final
    {
    public:
        using ClassType = EllipseByArcs2Impl<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;
        using Arc2 = Arc2<Real>;
        using Circle2 = Circle2<Real>;
        using PointsType = std::vector<Vector2D>;
        using Circle2Container = std::vector<Circle2>;

    public:
        EllipseByArcs2Impl(Real begin, Real end, size_t numArcs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const PointsType GetPoints() const;
        [[nodiscard]] const Circle2Container GetCircle2() const;

        [[nodiscard]] const Arc2 GetArc2(int index) const;
        [[nodiscard]] int getNumArcs() const;

    private:
        void Calculate(Real begin, Real end);

    private:
        PointsType m_Points;
        Circle2Container m_Circle;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H
