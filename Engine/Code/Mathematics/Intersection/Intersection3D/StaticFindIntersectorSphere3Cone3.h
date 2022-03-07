///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/02 22:38)

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
        using Vector3 = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Cone3 = Cone3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3 GetSphere() const noexcept;
        NODISCARD Cone3 GetCone() const noexcept;

        /// �ھ�̬�����ཻ��ѯ�У���������Բ׶��֮�䷢���ཻ������������޼��� �˺���������ӽ�Բ׶����Ľ��㡣
        NODISCARD Vector3 GetPoint() const noexcept;

    private:
        void Find();

    private:
        Sphere3 sphere;
        Cone3 cone;

        // ��Բ׶����������ཻ�㡣
        Vector3 point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
