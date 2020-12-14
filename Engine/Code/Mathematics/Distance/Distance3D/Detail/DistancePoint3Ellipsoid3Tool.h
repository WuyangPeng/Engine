///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/09 19:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistancePoint3Ellipsoid3Tool final
    {
    public:
        using ClassType = DistancePoint3Ellipsoid3Tool<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;

    public:
        DistancePoint3Ellipsoid3Tool(Real extent0, Real extent1, Real extent2, const Vector3D& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetSquaredDistance() const noexcept;
        [[nodiscard]] const Vector3D GetOutputVector() const noexcept;

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
        void ComputeSquaredDistanceSpecial(const Vector3D& extent, const Vector3D& queryPoint);

        // ��ƽ���㷨��Ѱ��F(t)��Ψһ����
        [[nodiscard]] const Container Bisector(const Container& extent, const Container& queryPoint);

    private:
        Vector3D m_Extent;
        Vector3D m_InputVector;
        Vector3D m_OutputVector;
        Real m_SquaredDistance;
        Real m_ZeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
