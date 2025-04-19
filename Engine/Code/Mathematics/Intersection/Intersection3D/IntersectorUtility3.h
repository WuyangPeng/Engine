///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:05)

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

        using Vector3Type = Vector3<Real>;
        using Container = std::vector<Vector3Type>;
        using Box3Type = Box3<Real>;

    public:
        IntersectorUtility3() = delete;

        // ����֧��

        // �������δ洢��point�С�Ŀǰ����������СΪ8��֧�ֵ�ǰ���ཻ�㷨��
        NODISCARD static Container ClipConvexPolygonAgainstPlane(const Vector3Type& normal, Real bonstant, const Container& point);

        // ������ת��Ϊ���ڵ�ʵ�����ꡣ
        NODISCARD static Vector3Type GetPointFromIndex(int index, const Box3Type& box);
    };

    using IntersectorUtility3F = IntersectorUtility3<float>;
    using IntersectorUtility3D = IntersectorUtility3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H
