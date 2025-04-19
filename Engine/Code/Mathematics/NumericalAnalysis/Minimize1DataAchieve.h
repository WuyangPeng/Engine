///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H

#include "Minimize1Data.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data() noexcept
    : minLocation{ MathType::maxReal }, minValue{ MathType::maxReal }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data(Real minLocation, Real minValue) noexcept
    : minLocation{ minLocation }, minValue{ minValue }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Minimize1Data<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Minimize1Data<Real>::GetMinLocation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minLocation;
}

template <typename Real>
Real Mathematics::Minimize1Data<Real>::GetMinValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinLocation(Real aMinLocation) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minLocation = aMinLocation;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinValue(Real aMinValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minValue = aMinValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetInitValue() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minLocation = MathType::maxReal;
    minValue = MathType::maxReal;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::CompareData(Real aMinLocation, Real aMinValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aMinValue < minValue)
    {
        minLocation = aMinLocation;
        minValue = aMinValue;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
