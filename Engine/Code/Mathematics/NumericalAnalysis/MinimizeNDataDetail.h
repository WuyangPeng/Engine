///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/15 14:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H

#include "MinimizeNData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::MinimizeNData<Real>::MinimizeNData() noexcept
    : minLocation{}, minValue{ Math::maxReal }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::MinimizeNData<Real>::MinimizeNData(const Container& minLocation, Real minValue)
    : minLocation{ minLocation }, minValue{ minValue }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::MinimizeNData<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>::GetMinLocationBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minLocation.begin();
}

template <typename Real>
typename Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>::GetMinLocationEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minLocation.end();
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>::GetMinValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minValue;
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>::GetMinLocation(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return minLocation.at(index);
}

template <typename Real>
int Mathematics::MinimizeNData<Real>::GetDimensions() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(minLocation.size());
}

template <typename Real>
void Mathematics::MinimizeNData<Real>::Set(Real newMinValue, Real newMinLocation, const Container& direction, int directionCurrent)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    minValue = newMinValue;

    auto index = 0;
    for (auto& value : minLocation)
    {
        const auto directionIndex = directionCurrent + index;
        value += newMinLocation * direction.at(directionIndex);
        ++index;
    }
}

template <typename Real>
typename const Mathematics::MinimizeNData<Real>::Container& Mathematics::MinimizeNData<Real>::GetMinLocation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minLocation;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H
