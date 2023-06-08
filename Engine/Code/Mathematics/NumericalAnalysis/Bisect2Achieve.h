///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H

#include "Bisect2.h"
#include "Bisect2RootDetail.h"
#include "Detail/Bisect2CalculateDetail.h"
#include "Detail/Bisect2NodeDetail.h"
#include "Detail/Bisect2StorageDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2<Real>::Bisect2(Function function0, Function function1, int maxLevel, Real tolerance) noexcept
    : function0{ function0 }, function1{ function1 }, maxLevel{ maxLevel }, tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2<Real>::IsValid() const noexcept
{
    if (function0 != nullptr && function1 != nullptr && 0 < maxLevel && Math::GetValue(0) <= tolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Bisect2Root<Real> Mathematics::Bisect2<Real>::Bisect(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Bisect2Calculate calculate{ *this, beginPointX, beginPointY, endPointX, endPointY };

    return calculate.GetRoot();
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetFunction0Value(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function0(x, y);
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetFunction1Value(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function1(x, y);
}

template <typename Real>
int Mathematics::Bisect2<Real>::GetMaxLevel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxLevel;
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tolerance;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H
