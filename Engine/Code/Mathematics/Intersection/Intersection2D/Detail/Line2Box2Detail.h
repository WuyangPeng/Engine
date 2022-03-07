///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/25 11:53)

#ifndef MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H

#include "Line2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::Line2Box2<Real>::Line2Box2(Real t0, Real t1, const Vector2& origin, const Vector2& direction, const Box2& box, bool solid)
    : rootCount{}, parameter{}, intersectionType{ IntersectionType::Empty }
{
    DoClipping(t0, t1, origin, direction, box, solid);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Line2Box2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Line2Box2<Real>::GetRootCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rootCount;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Line2Box2<Real>::GetParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return parameter.at(index);
}

template <typename Real>
Mathematics::IntersectionType Mathematics::Line2Box2<Real>::GetIntersects() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return intersectionType;
}

template <typename Real>
void Mathematics::Line2Box2<Real>::DoClipping(Real t0, Real t1, const Vector2& origin, const Vector2& direction, const Box2& box, bool solid)
{
    /// 将线性分量转换为盒子坐标。
    auto diff = origin - box.GetCenter();
    const Vector2 boxOrigin{ Vector2Tools::DotProduct(diff, box.GetAxis0()), Vector2Tools::DotProduct(diff, box.GetAxis1()) };
    const Vector2 boxDirection{ Vector2Tools::DotProduct(direction, box.GetAxis0()), Vector2Tools::DotProduct(direction, box.GetAxis1()) };

    const ClipType saveClipType{ t0, t1 };

    auto clipType = Clip(+boxDirection.GetX(), -boxOrigin.GetX() - box.GetExtent0(), saveClipType);
    clipType = Clip(-boxDirection.GetX(), +boxOrigin.GetX() - box.GetExtent0(), clipType);
    clipType = Clip(+boxDirection.GetY(), -boxOrigin.GetY() - box.GetExtent1(), clipType);
    clipType = Clip(-boxDirection.GetY(), +boxOrigin.GetY() - box.GetExtent1(), clipType);

    if (clipType.result && (solid || !Math::Approximate(t0, clipType.t0) || !Math::Approximate(t1, clipType.t1)))
    {
        if (t0 < t1)
        {
            intersectionType = IntersectionType::Segment;
            rootCount = 2;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            parameter[0] = origin + t0 * direction;
            parameter[1] = origin + t1 * direction;

#include STSTEM_WARNING_POP
        }
        else
        {
            intersectionType = IntersectionType::Point;
            rootCount = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            parameter[0] = origin + t0 * direction;

#include STSTEM_WARNING_POP
        }
    }
    else
    {
        intersectionType = IntersectionType::Empty;
        rootCount = 0;
    }
}

template <typename Real>
Mathematics::Line2Box2<Real>::ClipType::ClipType(Real t0, Real t1) noexcept
    : t0{ t0 }, t1{ t1 }, result{ false }
{
}

template <typename Real>
typename Mathematics::Line2Box2<Real>::ClipType Mathematics::Line2Box2<Real>::Clip(Real denom, Real numer, const ClipType& clipType) noexcept
{
    /// 如果线段与当前测试平面相交，则返回值为“ true”。 否则，将返回“ false”，在这种情况下，线段将被完全剪切。
    ClipType result{ clipType };

    if (Math::GetValue(0) < denom)
    {
        if (numer > denom * result.t1)
        {
            result.result = false;
            return result;
        }
        if (numer > denom * result.t0)
        {
            result.t0 = numer / denom;
        }
        result.result = true;
        return result;
    }
    else if (denom < Math::GetValue(0))
    {
        if (numer > denom * result.t0)
        {
            result.result = false;
            return result;
        }
        if (numer > denom * result.t1)
        {
            result.t1 = numer / denom;
        }
        result.result = true;
        return clipType;
    }
    else
    {
        result.result = numer <= Math::GetValue(0);
        return clipType;
    }
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H
