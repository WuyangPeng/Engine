///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 14:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H

#include "MinimizeNData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::MinimizeNData<Real>::MinimizeNData() noexcept
    : m_MinLocation{}, m_MinValue{ Math::sm_MaxReal }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::MinimizeNData<Real>::MinimizeNData(const Container& minLocation, Real minValue)
    : m_MinLocation{ minLocation }, m_MinValue{ minValue }
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
typename const Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>::GetMinLocationBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MinLocation.begin();
}

template <typename Real>
typename const Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>::GetMinLocationEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MinLocation.end();
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>::GetMinValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MinValue;
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>::GetMinLocation(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return m_MinLocation.at(index);
}

template <typename Real>
int Mathematics::MinimizeNData<Real>::GetDimensions() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_MinLocation.size());
}

template <typename Real>
void Mathematics::MinimizeNData<Real>::Set(Real minValue, Real minLocation, const Container& direction, int directionCurrent)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_MinValue = minValue;

    auto index = 0;
    for (auto& value : m_MinLocation)
    {
        const auto directionIndex = directionCurrent + index;
        value += minLocation * direction.at(directionIndex);
        ++index;
    }
}

template <typename Real>
typename const Mathematics::MinimizeNData<Real>::Container& Mathematics::MinimizeNData<Real>::GetMinLocation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinLocation;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H
