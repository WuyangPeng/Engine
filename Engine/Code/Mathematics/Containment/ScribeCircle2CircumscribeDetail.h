///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:41)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H

#include "ScribeCircle2Circumscribe.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::ScribeCircle2Circumscribe<Real>::ScribeCircle2Circumscribe(const Vector2& v0, const Vector2& v1, const Vector2& v2)
    : points{ v0, v1, v2 }, circle2{}, isCircleConstructed{ false }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::ScribeCircle2Circumscribe<Real>::Calculate()
{
    auto e10 = points.at(1) - points.at(0);
    auto e20 = points.at(2) - points.at(0);

    const std::array<std::array<Real, 2>, 2> matrix{ std::array<Real, 2>{ e10[0], e10[1] }, std::array<Real, 2>{ e20[0], e20[1] } };

    const std::array<Real, 2> inputVector{ Math::GetRational(1, 2) * Vector2Tools<Real>::GetLengthSquared(e10), Math::GetRational(1, 2) * Vector2Tools<Real>::GetLengthSquared(e20) };

    try
    {
        const LinearSystem<Real> linearSystem{};

        std::array<Real, 2> outputVector = linearSystem.Solve2(matrix, inputVector);

        const Vector2 solution{ outputVector.at(0), outputVector.at(1) };
        auto center = points.at(0) + solution;
        auto radius = Vector2Tools<Real>::GetLength(solution);

        circle2.SetCircle(center, radius);
        isCircleConstructed = true;
    }
    catch (CoreTools::Error&)
    {
        circle2 = Circle2();
        isCircleConstructed = false;
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ScribeCircle2Circumscribe<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ScribeCircle2Circumscribe<Real>::IsCircleConstructed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isCircleConstructed;
}

template <typename Real>
typename Mathematics::ScribeCircle2Circumscribe<Real>::Circle2 Mathematics::ScribeCircle2Circumscribe<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (isCircleConstructed)
    {
        return circle2;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入点是线性相关的！"s));
    }
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H
