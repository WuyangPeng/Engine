// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.2 (2019/07/17 17:29)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H

#include "ScribeCircle2Inscribe.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::ScribeCircle2Inscribe<Real>::ScribeCircle2Inscribe(const Vector2& v0, const Vector2& v1, const Vector2& v2)
    : m_Points{ v0, v1, v2 }, m_Circle2{}, m_IsCircleConstructed{ false }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::ScribeCircle2Inscribe<Real>::Calculate()
{
    auto d10 = m_Points.at(1) - m_Points.at(0);
    auto d20 = m_Points.at(2) - m_Points.at(0);
    auto d21 = m_Points.at(2) - m_Points.at(1);
    auto len10 = Vector2Tools<Real>::GetLength(d10);
    auto len20 = Vector2Tools<Real>::GetLength(d20);
    auto len21 = Vector2Tools<Real>::GetLength(d21);
    auto perimeter = len10 + len20 + len21;
    if (Math<Real>::GetZeroTolerance() < perimeter)
    {
        len10 /= perimeter;
        len20 /= perimeter;
        len21 /= perimeter;

        auto center = len21 * m_Points.at(0) + len20 * m_Points.at(1) + len10 * m_Points.at(2);
        auto radius = Math<Real>::FAbs(Vector2Tools<Real>::DotPerp(d10, d20)) / perimeter;

        m_Circle2.SetCircle(center, radius);
        m_IsCircleConstructed = true;
    }
    else
    {
        m_Circle2 = Circle2{};
        m_IsCircleConstructed = false;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ScribeCircle2Inscribe<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ScribeCircle2Inscribe<Real>::IsCircleConstructed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_IsCircleConstructed;
}

template <typename Real>
const typename Mathematics::ScribeCircle2Inscribe<Real>::Circle2 Mathematics::ScribeCircle2Inscribe<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_IsCircleConstructed)
    {
        return m_Circle2;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入点是线性相关的！"));
    }
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H
