///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/12 14:14)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H

#include "ScribeCircle2Inscribe.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::ScribeCircle2Inscribe<Real>::ScribeCircle2Inscribe(const Vector2& v0, const Vector2& v1, const Vector2& v2)
    : points{ v0, v1, v2 }, circle2{}, isCircleConstructed{ false }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::ScribeCircle2Inscribe<Real>::Calculate()
{
    auto d10 = points.at(1) - points.at(0);
    auto d20 = points.at(2) - points.at(0);
    auto d21 = points.at(2) - points.at(1);
    auto len10 = Vector2Tools<Real>::GetLength(d10);
    auto len20 = Vector2Tools<Real>::GetLength(d20);
    auto len21 = Vector2Tools<Real>::GetLength(d21);
    auto perimeter = len10 + len20 + len21;
    if (Math<Real>::GetZeroTolerance() < perimeter)
    {
        len10 /= perimeter;
        len20 /= perimeter;
        len21 /= perimeter;

        auto center = len21 * points.at(0) + len20 * points.at(1) + len10 * points.at(2);
        auto radius = Math<Real>::FAbs(Vector2Tools<Real>::DotPerp(d10, d20)) / perimeter;

        circle2.SetCircle(center, radius);
        isCircleConstructed = true;
    }
    else
    {
        circle2 = Circle2{};
        isCircleConstructed = false;
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

    return isCircleConstructed;
}

template <typename Real>
typename Mathematics::ScribeCircle2Inscribe<Real>::Circle2 Mathematics::ScribeCircle2Inscribe<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (isCircleConstructed)
    {
        return circle2;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入点是线性相关的！"));
    }
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_DETAIL_H
