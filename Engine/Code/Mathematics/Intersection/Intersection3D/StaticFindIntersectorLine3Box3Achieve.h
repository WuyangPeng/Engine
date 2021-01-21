///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 13:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_ACHIEVE_H

#include "StaticFindIntersectorLine3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Box3<Real>::StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Box{ box }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Box3<Real>::Find()
{
    constexpr auto t0 = -Math::sm_MaxReal;
    constexpr auto t1 = Math::sm_MaxReal;
    const auto findShared = DoClipping(t0, t1, m_Line.GetOrigin(), m_Line.GetDirection(), m_Box, true);
    this->SetIntersectionType(findShared.m_IntersectionType);
    m_Quantity = findShared.m_Quantity;
    m_Point0 = findShared.m_Point0;
    m_Point1 = findShared.m_Point1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Box3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Box3<Real>::DoClipping(Real t0, Real t1, const Vector3D& origin, const Vector3D& direction, const Box3& box, bool solid)
{
    FindShared findShared{};

    // 将线性分量转换为框坐标。
    auto diff = origin - box.GetCenter();
    const Vector3D boxOrigin{ Vector3DTools::DotProduct(diff, box.GetAxis(0)), Vector3DTools::DotProduct(diff, box.GetAxis(1)), Vector3DTools::DotProduct(diff, box.GetAxis(2)) };
    const Vector3D boxDirection{ Vector3DTools::DotProduct(direction, box.GetAxis(0)), Vector3DTools::DotProduct(direction, box.GetAxis(1)), Vector3DTools::DotProduct(direction, box.GetAxis(2)) };

    auto notAllClipped = Clip(+boxDirection.GetX(), -boxOrigin.GetX() - box.GetExtent(0), t0, t1);
    if (notAllClipped.m_Result)
    {
        notAllClipped = Clip(-boxDirection.GetX(), +boxOrigin.GetX() - box.GetExtent(0), notAllClipped.m_T0, notAllClipped.m_T1);
    }
    if (notAllClipped.m_Result)
    {
        notAllClipped = Clip(+boxDirection.GetY(), -boxOrigin.GetY() - box.GetExtent(1), notAllClipped.m_T0, notAllClipped.m_T1);
    }
    if (notAllClipped.m_Result)
    {
        notAllClipped = Clip(-boxDirection.GetY(), +boxOrigin.GetY() - box.GetExtent(1), notAllClipped.m_T0, notAllClipped.m_T1);
    }
    if (notAllClipped.m_Result)
    {
        notAllClipped = Clip(+boxDirection.GetZ(), -boxOrigin.GetZ() - box.GetExtent(2), notAllClipped.m_T0, notAllClipped.m_T1);
    }
    if (notAllClipped.m_Result)
    {
        notAllClipped = Clip(-boxDirection.GetZ(), +boxOrigin.GetZ() - box.GetExtent(2), notAllClipped.m_T0, notAllClipped.m_T1);
    }

    if (notAllClipped.m_Result && (solid || Math::Approximate(notAllClipped.m_T0, t0) || Math::Approximate(notAllClipped.m_T1, t1)))
    {
        if (notAllClipped.m_T0 < notAllClipped.m_T1)
        {
            findShared.m_IntersectionType = IntersectionType::Segment;
            findShared.m_Quantity = 2;
            findShared.m_Point0 = origin + t0 * direction;
            findShared.m_Point1 = origin + t1 * direction;
        }
        else
        {
            findShared.m_IntersectionType = IntersectionType::Point;
            findShared.m_Quantity = 1;
            findShared.m_Point0 = origin + t0 * direction;
        }
    }
    else
    {
        findShared.m_Quantity = 0;
        findShared.m_IntersectionType = IntersectionType::Empty;
    }

    return findShared;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Box3<Real>::ClipType Mathematics::StaticFindIntersectorLine3Box3<Real>::Clip(Real denom, Real numer, Real t0, Real t1) noexcept
{
    ClipType clipType{};
    clipType.m_T0 = t0;
    clipType.m_T1 = t1;

    // 如果线段与当前测试平面相交，则返回值为“true”。 否则，将返回“false”，在这种情况下，线段将被完全剪切。
    if (Math::GetValue(0) < denom)
    {
        if (denom * t1 < numer)
        {
            return clipType;
        }
        if (denom * t0 < numer)
        {
            clipType.m_T0 = numer / denom;
        }

        clipType.m_Result = true;
        return clipType;
    }
    else if (denom < Math::GetValue(0))
    {
        if (denom * t0 < numer)
        {
            return clipType;
        }
        if (denom * t1 < numer)
        {
            clipType.m_T1 = numer / denom;
        }

        clipType.m_Result = true;
        return clipType;
    }
    else
    {
        clipType.m_Result = numer <= Math::GetValue(0);
        return clipType;
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_ACHIEVE_H