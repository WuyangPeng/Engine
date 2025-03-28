///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:06)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cone3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Cone3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Cone3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Cone3 = Cone3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Cone3(const Line3& line, const Cone3& cone, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Cone3 GetCone() const noexcept;

        /// �ཻ���� ���ܵ��ཻ��������
        /// IT_EMTPY��û�н���
        /// IT_POINT��point0�ǽ���
        /// IT_SEGMENT��<point0,point1>���ཻ�߶�
        /// IT_RAY��point0 + t * point1���ཻ����
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Line3 line;
        Cone3 cone;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
