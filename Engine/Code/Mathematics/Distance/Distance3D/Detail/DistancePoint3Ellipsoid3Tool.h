///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/22 15:49)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Ellipsoid3Tool final
    {
    public:
        using ClassType = DistancePoint3Ellipsoid3Tool<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;

    public:
        DistancePoint3Ellipsoid3Tool(Real extent0, Real extent1, Real extent2, const Vector3& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSquaredDistance() const noexcept;
        NODISCARD Vector3 GetOutputVector() const noexcept;

    private:
        using Container = std::vector<Real>;

    private:
        // ��Բ��(x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1��e0 >= e1 >= e2��
        // ��ѯ����(y0,y1,y2)�� y0 >= 0 ,y1 >= 0��y2 >= 0
        // �������شӲ�ѯ�㵽��Բ��ƽ�����롣
        // ��Ҳ�����ڵ�һ������ӽ�(y0,y1,y2)����Բ��(x0,x1,x2) ��
        void ComputeSquaredDistance();

        // ��Բ�� (x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1��
        // ��ѯ���� (y0,y1,y2)��
        // �������شӲ�ѯ�㵽��Բ��ƽ�����롣
        // ��Ҳ������ӽ�(y0,y1,y2)����Բ�� (x0,x1,x2)  ��
        void ComputeSquaredDistanceSpecial(const Vector3& extent, const Vector3& queryPoint);

        // ��ƽ���㷨��Ѱ��F(t)��Ψһ����
        NODISCARD Container Bisector(const Container& extent, const Container& queryPoint);

    private:
        Vector3 toolExtent;
        Vector3 inputVector;
        Vector3 outputVector;
        Real squaredDistance;
        Real zeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
