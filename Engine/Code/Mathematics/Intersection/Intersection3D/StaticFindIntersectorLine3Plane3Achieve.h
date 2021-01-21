///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 10:47)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Plane3<Real>::StaticFindIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, m_Line{ line }, m_Plane{ plane }, m_LineParameter{}
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
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine3Plane3<Real>::Find() noexcept
{
    auto directionDotNormal = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Plane.GetNormal());
    auto signedDistance = m_Plane.DistanceTo(m_Line.GetOrigin());
    if (Math::GetZeroTolerance() < Math::FAbs(directionDotNormal))
    {
        // 该线不平行于平面，因此它们必须相交。
        m_LineParameter = -signedDistance / directionDotNormal;

        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // 线和平面平行。 确定它们在数值上是否足够接近以重合。
    if (Math::FAbs(signedDistance) <= Math::GetZeroTolerance())
    {
        // 该线与平面重合，因此将参数选择为t = 0。
        m_LineParameter = Math::GetValue(0);
        this->SetIntersectionType(IntersectionType::Line);

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Plane3<Real>::GetLineParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LineParameter;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_ACHIEVE_H