///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/25 11:52)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorUtility3 final
    {
    public:
        using ClassType = IntersectorUtility3<Real>;
        using Vector3D = Vector3D<Real>;
        using Container = std::vector<Vector3D>;
        using Box3 = Box3<Real>;

    public:
        IntersectorUtility3() = delete;

        // ����֧��

        // �������δ洢��point�С�Ŀǰ����������СΪ8��֧�ֵ�ǰ���ཻ�㷨��
        [[nodiscard]] static Container ClipConvexPolygonAgainstPlane(const Vector3D& normal, Real bonstant, const Container& point);

        // ������ת��Ϊ���ڵ�ʵ�����ꡣ
        [[nodiscard]] static Vector3D GetPointFromIndex(int index, const Box3& box);
    };

    using FloatIntersectorUtility3 = IntersectorUtility3<float>;
    using DoubleIntersectorUtility3 = IntersectorUtility3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H
