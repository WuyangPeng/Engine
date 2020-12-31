///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/08 15:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistancePoint2Ellipse2Tool final
    {
    public:
        using ClassType = DistancePoint2Ellipse2Tool<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;

    public:
        DistancePoint2Ellipse2Tool(Real extent0, Real extent1, const Vector2D& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetSquaredDistance() const noexcept;
        [[nodiscard]] const Vector2D GetOutputVector() const noexcept;

    private:
        // ��Բ��(x0 / e0)^2 + (x1 / e1)^2 = 1��e0 >= e1��
        // ��ѯ����(y0,y1)�� y0 >= 0 ��y1 >= 0
        // �������شӲ�ѯ�㵽��Բ��ƽ�����롣
        // ��Ҳ�����ڵ�һ������ӽ�(y0,y1)����Բ�� (x0,x1) ��
        void ComputeSquaredDistance();

        // ��Բ�� (x0 / e0)^2 + (x1 / e1)^2 = 1��
        // ��ѯ���� (y0,y1)��
        // �������شӲ�ѯ�㵽��Բ��ƽ�����롣
        // ��Ҳ������ӽ�(y0,y1)����Բ�� (x0,x1) ��
        void ComputeSquaredDistanceSpecial(const Vector2D& extent, const Vector2D& queryPoint);

    private:
        Vector2D m_Extent;
        Vector2D m_InputVector;
        Vector2D m_OutputVector;
        Real m_SquaredDistance;
        Real m_ZeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
