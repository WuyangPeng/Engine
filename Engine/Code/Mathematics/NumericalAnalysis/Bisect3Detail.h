// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 13:41)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_DETAIL_H

#include "Bisect3.h"
#include "Bisect3Calculate.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3<Real>
	::Bisect3(Function firstFunction, Function secondFunction, Function thirdFunction, int maxLevel, Real tolerance)
	: m_FirstFunction{ firstFunction }, m_SecondFunction{ secondFunction }, m_ThirdFunction{ thirdFunction }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3<Real>
	::IsValid() const noexcept
{
	if (m_FirstFunction != nullptr && m_SecondFunction != nullptr && m_ThirdFunction != nullptr && 0 < m_MaxLevel && Math<Real>::sm_Zero <= m_Tolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect3<Real>::Bisect3Root Mathematics::Bisect3<Real>
	::Bisect(Real beginPointX, Real beginPointY, Real beginPointZ,
			 Real endPointX, Real endPointY, Real endPointZ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Bisect3Calculate calculate{ *this,beginPointX,beginPointY,beginPointZ,
								endPointX,endPointY, endPointZ };

	return calculate.GetRoot();
}

template <typename Real>
Real Mathematics::Bisect3<Real>
	::GetFirstFunctionValue(Real x, Real y, Real z) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_FirstFunction(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>
	::GetSecondFunctionValue(Real x, Real y, Real z)const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SecondFunction(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>
	::GetThirdFunctionValue(Real x, Real y, Real z)const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ThirdFunction(x, y, z);
}

template <typename Real>
int Mathematics::Bisect3<Real>
	::GetMaxLevel() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxLevel;
}

template <typename Real>
Real Mathematics::Bisect3<Real>
	::GetTolerance() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Tolerance;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_DETAIL_H

