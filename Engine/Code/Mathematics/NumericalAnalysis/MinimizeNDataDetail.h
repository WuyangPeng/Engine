// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/20 14:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H

#include "MinimizeNData.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::MinimizeNData<Real>
	::MinimizeNData()
	:m_MinLocation{}, m_MinValue{ Math<Real>::sm_MaxReal }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::MinimizeNData<Real>
	::MinimizeNData(const RealVector& minLocation, Real minValue)
	:m_MinLocation{ minLocation }, m_MinValue{ minValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::MinimizeNData<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

template <typename Real>
typename const Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>
	::GetMinLocationBegin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MinLocation.begin();
}

template <typename Real>
typename const Mathematics::MinimizeNData<Real>::ConstIter Mathematics::MinimizeNData<Real>
	::GetMinLocationEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MinLocation.end();
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>
	::GetMinValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MinValue;
}

template <typename Real>
Real Mathematics::MinimizeNData<Real>
	::GetMinLocation(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_MinLocation.size()), "Ë÷Òý´íÎó");

	return m_MinLocation[index];
}

template <typename Real>
int Mathematics::MinimizeNData<Real>
	::GetDimensions() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_MinLocation.size());
}

template <typename Real>
void Mathematics::MinimizeNData<Real>
	::Set(Real minValue, Real minLocation, const Real* directionCurrent)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_MinValue = minValue;

	auto dimensions = GetDimensions();
	for (int j = 0; j < dimensions; ++j)
	{
		m_MinLocation[j] += minLocation * directionCurrent[j];
	}
}

template <typename Real>
typename const  Mathematics::MinimizeNData<Real>::RealVector& Mathematics::MinimizeNData<Real>
	::GetMinLocation() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinLocation;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_DETAIL_H

