///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Ellipse3.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorPlane3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Cylinder3 = Cylinder3<Real>;
        using Line3 = Line3<Real>;
        using Circle3 = Circle3<Real>;
        using Ellipse3 = Ellipse3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using TwoLine = std::pair<Line3, Line3>;

    public:
        StaticFindIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetPlane() const noexcept;
        NODISCARD Cylinder3 GetCylinder() const noexcept;

        // �޳�֧�֡� ��׶̨����Ϊλ��ƽ������ࡣ ���Բ����λ��ƽ��ĸ��࣬�����޳���
        NODISCARD bool CylinderIsCulled() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // *����*Բ�����ƽ��Ľ�����
        enum class CylinderPlaneIntersection
        {
            EmptySet,
            OneLine,
            TwoLines,
            Circle,
            Ellipse
        };

        NODISCARD CylinderPlaneIntersection GetType() const noexcept;

        // ��GetType()����OneLineʱ��Ч��
        Line3 GetOneLine() const noexcept;

        // ��GetType()����TwoLinesʱ��Ч��
        TwoLine GetTwoLines() const noexcept;

        // ��GetType()����Circleʱ��Ч��
        Circle3 GetCircle() const noexcept;

        // ��GetType()����Ellipseʱ��Ч��
        Ellipse3 GetEllipse() const noexcept;

    private:
        // *����*Բ����ľ�̬�����ѯ��
        void Find();

    private:
        Plane3 plane;
        Cylinder3 cylinder;

        // Բ������ʱ���ཻ���á�
        CylinderPlaneIntersection type;
        Line3 line0;
        Line3 line1;
        Circle3 circle;
        Ellipse3 ellipse;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
