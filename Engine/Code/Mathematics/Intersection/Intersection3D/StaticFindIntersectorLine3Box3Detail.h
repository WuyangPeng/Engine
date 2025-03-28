///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:24)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H

#include "StaticFindIntersectorLine3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Box3<Real>::StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, box{ box }, quantity{}, point0{}, point1{}
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
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Box3<Real>::Find()
{
    constexpr auto t0 = -MathType::maxReal;
    constexpr auto t1 = MathType::maxReal;
    const auto findShared = DoClipping(t0, t1, line.GetOrigin(), line.GetDirection(), box, true);
    this->SetIntersectionType(findShared.intersectionType);
    quantity = findShared.quantity;
    point0 = findShared.point0;
    point1 = findShared.point1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Box3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Box3<Real>::DoClipping(Real t0, Real t1, const Vector3Type& origin, const Vector3Type& direction, const Box3& box, bool solid)
{
    FindShared findShared{};

    // 将线性分量转换为框坐标。
    auto diff = origin - box.GetCenter();
    const Vector3 boxOrigin{ Vector3ToolsType::DotProduct(diff, box.GetAxis(0)), Vector3ToolsType::DotProduct(diff, box.GetAxis(1)), Vector3ToolsType::DotProduct(diff, box.GetAxis(2)) };
    const Vector3 boxDirection{ Vector3ToolsType::DotProduct(direction, box.GetAxis(0)), Vector3ToolsType::DotProduct(direction, box.GetAxis(1)), Vector3ToolsType::DotProduct(direction, box.GetAxis(2)) };

    auto notAllClipped = Clip(+boxDirection.GetX(), -boxOrigin.GetX() - box.GetExtent(0), t0, t1);
    if (notAllClipped.result)
    {
        notAllClipped = Clip(-boxDirection.GetX(), +boxOrigin.GetX() - box.GetExtent(0), notAllClipped.t0, notAllClipped.t1);
    }
    if (notAllClipped.result)
    {
        notAllClipped = Clip(+boxDirection.GetY(), -boxOrigin.GetY() - box.GetExtent(1), notAllClipped.t0, notAllClipped.t1);
    }
    if (notAllClipped.result)
    {
        notAllClipped = Clip(-boxDirection.GetY(), +boxOrigin.GetY() - box.GetExtent(1), notAllClipped.t0, notAllClipped.t1);
    }
    if (notAllClipped.result)
    {
        notAllClipped = Clip(+boxDirection.GetZ(), -boxOrigin.GetZ() - box.GetExtent(2), notAllClipped.t0, notAllClipped.t1);
    }
    if (notAllClipped.result)
    {
        notAllClipped = Clip(-boxDirection.GetZ(), +boxOrigin.GetZ() - box.GetExtent(2), notAllClipped.t0, notAllClipped.t1);
    }

    if (notAllClipped.result && (solid || MathType::Approximate(notAllClipped.t0, t0) || MathType::Approximate(notAllClipped.t1, t1)))
    {
        if (notAllClipped.t0 < notAllClipped.t1)
        {
            findShared.intersectionType = IntersectionType::Segment;
            findShared.quantity = 2;
            findShared.point0 = origin + t0 * direction;
            findShared.point1 = origin + t1 * direction;
        }
        else
        {
            findShared.intersectionType = IntersectionType::Point;
            findShared.quantity = 1;
            findShared.point0 = origin + t0 * direction;
        }
    }
    else
    {
        findShared.quantity = 0;
        findShared.intersectionType = IntersectionType::Empty;
    }

    return findShared;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Box3<Real>::ClipType Mathematics::StaticFindIntersectorLine3Box3<Real>::Clip(Real denom, Real numer, Real t0, Real t1) noexcept
{
    ClipType clipType{};
    clipType.t0 = t0;
    clipType.t1 = t1;

    // 如果线段与当前测试平面相交，则返回值为“true”。 否则，将返回“false”，在这种情况下，线段将被完全剪切。
    if (MathType::GetValue(0) < denom)
    {
        if (denom * t1 < numer)
        {
            return clipType;
        }
        if (denom * t0 < numer)
        {
            clipType.t0 = numer / denom;
        }

        clipType.result = true;
        return clipType;
    }
    else if (denom < MathType::GetValue(0))
    {
        if (denom * t0 < numer)
        {
            return clipType;
        }
        if (denom * t1 < numer)
        {
            clipType.t1 = numer / denom;
        }

        clipType.result = true;
        return clipType;
    }
    else
    {
        clipType.result = numer <= MathType::GetValue(0);
        return clipType;
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_DETAIL_H