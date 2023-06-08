///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:18)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
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
    class EllipseByArcs2 final
    {
    public:
        using ClassType = EllipseByArcs2<Real>;

        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;
        using Arc2 = Arc2<Real>;
        using Circle2 = Circle2<Real>;
        using PointsType = std::vector<Vector2>;
        using Circle2Container = std::vector<Circle2>;

    public:
        EllipseByArcs2(Real begin, Real end, size_t numArcs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PointsType GetPoints() const;
        NODISCARD Circle2Container GetCircle2() const;

        NODISCARD Arc2 GetArc2(int index) const;
        NODISCARD int GetNumArcs() const;

    private:
        void Calculate(Real begin, Real end);

    private:
        PointsType points;
        Circle2Container circle;
    };

    using EllipseByArcs2F = EllipseByArcs2<float>;
    using EllipseByArcs2D = EllipseByArcs2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
