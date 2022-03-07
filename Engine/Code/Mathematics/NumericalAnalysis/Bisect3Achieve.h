///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/14 13:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H

#include "Bisect3.h"
#include "Bisect3RootDetail.h"
#include "Detail/Bisect3Calculate.h"
#include "Detail/Bisect3CalculateDetail.h"
#include "Detail/Bisect3NodeDetail.h"
#include "Detail/Bisect3StorageDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3<Real>::Bisect3(Function function0, Function function1, Function function2, int maxLevel, Real tolerance) noexcept
    : function0{ function0 }, function1{ function1 }, function2{ function2 }, maxLevel{ maxLevel }, tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3<Real>::IsValid() const noexcept
{
    if (function0 != nullptr && function1 != nullptr && function2 != nullptr && 0 < maxLevel && Math::GetValue(0) <= tolerance)
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
typename Mathematics::Bisect3<Real>::Bisect3Root Mathematics::Bisect3<Real>::Bisect(Real beginPointX, Real beginPointY, Real beginPointZ, Real endPointX, Real endPointY, Real endPointZ) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Bisect3Calculate calculate{ *this, beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ };

    return calculate.GetRoot();
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction0Value(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function0(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction1Value(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function1(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction2Value(Real x, Real y, Real z) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function2(x, y, z);
}

template <typename Real>
int Mathematics::Bisect3<Real>::GetMaxLevel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxLevel;
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tolerance;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H
