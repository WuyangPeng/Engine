///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cone3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSphere3Cone3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSphere3Cone3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Cone3Type = Cone3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorSphere3Cone3(const Sphere3Type& sphere, const Cone3Type& cone, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3Type GetSphere() const noexcept;
        NODISCARD Cone3Type GetCone() const noexcept;

        /// �ھ�̬�����ཻ��ѯ�У���������Բ׶��֮�䷢���ཻ������������޼��� �˺���������ӽ�Բ׶����Ľ��㡣
        NODISCARD Vector3Type GetPoint() const noexcept;

    private:
        void Find();

    private:
        Sphere3Type sphere;
        Cone3Type cone;

        // ��Բ׶����������ཻ�㡣
        Vector3Type point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
