///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 16:28)

#ifndef MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H

#include "Line2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::Line2Box2<Real>::Line2Box2(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box, bool solid)
    : m_RootCount{}, m_Parameter{}, m_IntersectionType{ IntersectionType::Empty }
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

    return m_RootCount;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::Line2Box2<Real>::GetParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Parameter.at(index);
}

template <typename Real>
Mathematics::IntersectionType Mathematics::Line2Box2<Real>::GetIntersects() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_IntersectionType;
}

template <typename Real>
void Mathematics::Line2Box2<Real>::DoClipping(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box, bool solid)
{
    /// 将线性分量转换为盒子坐标。
    auto diff = origin - box.GetCenter();
    const Vector2D boxOrigin{ Vector2DTools::DotProduct(diff, box.GetAxis0()), Vector2DTools::DotProduct(diff, box.GetAxis1()) };
    const Vector2D boxDirection{ Vector2DTools::DotProduct(direction, box.GetAxis0()), Vector2DTools::DotProduct(direction, box.GetAxis1()) };

    const ClipType saveClipType{ t0, t1 };

    auto clipType = Clip(+boxDirection.GetX(), -boxOrigin.GetX() - box.GetExtent0(), saveClipType);
    clipType = Clip(-boxDirection.GetX(), +boxOrigin.GetX() - box.GetExtent0(), clipType);
    clipType = Clip(+boxDirection.GetY(), -boxOrigin.GetY() - box.GetExtent1(), clipType);
    clipType = Clip(-boxDirection.GetY(), +boxOrigin.GetY() - box.GetExtent1(), clipType);

    if (clipType.m_Result && (solid || !Math::Approximate(t0, clipType.m_T0) || !Math::Approximate(t1, clipType.m_T1)))
    {
        if (t0 < t1)
        {
            m_IntersectionType = IntersectionType::Segment;
            m_RootCount = 2;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Parameter[0] = origin + t0 * direction;
            m_Parameter[1] = origin + t1 * direction;
#include STSTEM_WARNING_POP
        }
        else
        {
            m_IntersectionType = IntersectionType::Point;
            m_RootCount = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Parameter[0] = origin + t0 * direction;
#include STSTEM_WARNING_POP
        }
    }
    else
    {
        m_IntersectionType = IntersectionType::Empty;
        m_RootCount = 0;
    }
}

template <typename Real>
Mathematics::Line2Box2<Real>::ClipType::ClipType(Real t0, Real t1) noexcept
    : m_T0{ t0 }, m_T1{ t1 }, m_Result{ false }
{
}

template <typename Real>
typename Mathematics::Line2Box2<Real>::ClipType Mathematics::Line2Box2<Real>::Clip(Real denom, Real numer, const ClipType& clipType) noexcept
{
    /// 如果线段与当前测试平面相交，则返回值为“ true”。 否则，将返回“ false”，在这种情况下，线段将被完全剪切。
    ClipType result{ clipType };

    if (Math::GetValue(0) < denom)
    {
        if (numer > denom * result.m_T1)
        {
            result.m_Result = false;
            return result;
        }
        if (numer > denom * result.m_T0)
        {
            result.m_T0 = numer / denom;
        }
        result.m_Result = true;
        return result;
    }
    else if (denom < Math::GetValue(0))
    {
        if (numer > denom * result.m_T0)
        {
            result.m_Result = false;
            return result;
        }
        if (numer > denom * result.m_T1)
        {
            result.m_T1 = numer / denom;
        }
        result.m_Result = true;
        return clipType;
    }
    else
    {
        result.m_Result = numer <= Math::GetValue(0);
        return clipType;
    }
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_BOX2_DETAIL_H
