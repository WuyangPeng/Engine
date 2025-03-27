///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:47)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint2Ellipse2Tool final
    {
    public:
        using ClassType = DistancePoint2Ellipse2Tool<Real>;

        using Vector2 = Vector2<Real>;
        using MathType = Math<Real>;

    public:
        DistancePoint2Ellipse2Tool(Real extent0, Real extent1, const Vector2& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSquaredDistance() const noexcept;
        NODISCARD Vector2 GetOutputVector() const noexcept;

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
        void ComputeSquaredDistanceSpecial(const Vector2& localExtent, const Vector2& queryPoint);

    private:
        Vector2 extent;
        Vector2 inputVector;
        Vector2 outputVector;
        Real squaredDistance;
        Real zeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
