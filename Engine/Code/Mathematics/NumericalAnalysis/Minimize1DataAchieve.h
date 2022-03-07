///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/15 11:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H

#include "Minimize1Data.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data() noexcept
    : mMinLocation{ Math::maxReal }, mMinValue{ Math::maxReal }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data(Real minLocation, Real minValue) noexcept
    : mMinLocation{ minLocation }, mMinValue{ minValue }
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

    return mMinLocation;
}

template <typename Real>
Real Mathematics::Minimize1Data<Real>::GetMinValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return mMinValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinLocation(Real minLocation) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mMinLocation = minLocation;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinValue(Real minValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mMinValue = minValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetInitValue() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mMinLocation = Math::maxReal;
    mMinValue = Math::maxReal;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::CompareData(Real minLocation, Real minValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (minValue < mMinValue)
    {
        mMinLocation = minLocation;
        mMinValue = minValue;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
