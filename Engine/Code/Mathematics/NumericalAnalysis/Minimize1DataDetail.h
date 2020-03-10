// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 17:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_DETAIL_H

#include "Minimize1Data.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Minimize1Data<Real>
	::Minimize1Data()
	:m_MinLocation{ Math<Real>::sm_MaxReal }, m_MinValue{ Math<Real>::sm_MaxReal }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Minimize1Data<Real>
	::Minimize1Data(Real minLocation, Real minValue)
	:m_MinLocation{ minLocation }, m_MinValue{ minValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Minimize1Data<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

template <typename Real>
Real Mathematics::Minimize1Data<Real>
	::GetMinLocation() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MinLocation;
}

template <typename Real>
Real Mathematics::Minimize1Data<Real>
	::GetMinValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MinValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>
	::SetMinLocation(Real minLocation)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_MinLocation = minLocation;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>
	::SetMinValue(Real minValue)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_MinValue = minValue;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>	
	::SetInitValue() 
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_MinLocation = Math<Real>::sm_MaxReal;
	m_MinValue = Math<Real>::sm_MaxReal;
}

template <typename Real>
void Mathematics::Minimize1Data<Real>
	::CompareData(Real minLocation, Real minValue)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (minValue < m_MinValue)
	{
		m_MinLocation = minLocation;
		m_MinValue = minValue;
	}
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_DETAIL_H

