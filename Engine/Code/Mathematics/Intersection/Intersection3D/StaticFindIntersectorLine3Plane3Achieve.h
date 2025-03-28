///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Plane3<Real>::StaticFindIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, line{ line }, plane{ plane }, lineParameter{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Plane3<Real>::Find() noexcept
{
    auto directionDotNormal = Vector3ToolsType::DotProduct(line.GetDirection(), plane.GetNormal());
    auto signedDistance = plane.DistanceTo(line.GetOrigin());
    if (MathType::GetZeroTolerance() < MathType::FAbs(directionDotNormal))
    {
        // ���߲�ƽ����ƽ�棬������Ǳ����ཻ��
        lineParameter = -signedDistance / directionDotNormal;

        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // �ߺ�ƽ��ƽ�С� ȷ����������ֵ���Ƿ��㹻�ӽ����غϡ�
    if (MathType::FAbs(signedDistance) <= MathType::GetZeroTolerance())
    {
        // ������ƽ���غϣ���˽�����ѡ��Ϊt = 0��
        lineParameter = MathType::GetValue(0);
        this->SetIntersectionType(IntersectionType::Line);

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetLineParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineParameter;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H