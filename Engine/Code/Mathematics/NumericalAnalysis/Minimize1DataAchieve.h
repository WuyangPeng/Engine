///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 14:04)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H

#include "Minimize1Data.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data() noexcept
    : m_MinLocation{ Math::sm_MaxReal }, m_MinValue{ Math::sm_MaxReal }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Minimize1Data<Real>::Minimize1Data(Real minLocation, Real minValue) noexcept
    : m_MinLocation{ minLocation }, m_MinValue{ minValue }
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

    return m_MinLocation;
}

template <typename Real>
Real Mathematics::Minimize1Data<Real>::GetMinValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MinValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinLocation(Real minLocation) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_MinLocation = minLocation;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetMinValue(Real minValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_MinValue = minValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::SetInitValue() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_MinLocation = Math::sm_MaxReal;
    m_MinValue = Math::sm_MaxReal;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>::CompareData(Real minLocation, Real minValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (minValue < m_MinValue)
    {
        m_MinLocation = minLocation;
        m_MinValue = minValue;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_ACHIEVE_H
