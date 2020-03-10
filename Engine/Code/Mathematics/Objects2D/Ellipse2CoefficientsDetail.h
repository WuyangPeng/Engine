// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/06 11:26)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H

#include "Ellipse2Coefficients.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>
	::Ellipse2Coefficients( const Matrix2& matrix,const Vector2D& vector, Real constants )
	:m_Coefficients{ constants ,vector[0] ,vector[1] ,matrix(0,0),matrix(0,1) * static_cast<Real>(2),matrix(1,1) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::Ellipse2Coefficients<Real>
	::Ellipse2Coefficients( const std::vector<Real>& coefficient )
	:m_Coefficients{ coefficient }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2Coefficients<Real>
	::IsValid() const noexcept
{
	if(m_Coefficients.size() == 6)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const  Mathematics::Ellipse2Coefficients<Real>::Matrix2 Mathematics::Ellipse2Coefficients<Real>
	::GetMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Matrix2{ m_Coefficients[3],static_cast<Real>(0.5) * m_Coefficients[4],static_cast<Real>(0.5) * m_Coefficients[4],m_Coefficients[5] };
}

template <typename Real>
typename const  Mathematics::Ellipse2Coefficients<Real>::Vector2D Mathematics::Ellipse2Coefficients<Real>
	::GetVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Vector2D{ m_Coefficients[1],m_Coefficients[2] };
}


template <typename Real>
Real Mathematics::Ellipse2Coefficients<Real>
	::GetConstants() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Coefficients[0];
}

template <typename Real>
typename const Mathematics::Ellipse2Coefficients<Real>::CoefficientsType Mathematics::Ellipse2Coefficients<Real>
	::GetCoefficients() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	std::vector<Real> coefficients(m_Coefficients);

	// 安排x0^2或x1^2系数之一是1。
	auto maxValue = Math::FAbs(coefficients[3]);
	int maxIndex{ 3 };
	auto absValue = Math::FAbs(coefficients[5]);
	if (maxValue < absValue)
	{
		maxValue = absValue;
		maxIndex = 5;
	}

	auto invMaxValue = static_cast<Real>(1) / maxValue;
	for (auto i = 0; i < 6; ++i)
	{
		if (i != maxIndex)
		{
			coefficients[i] *= invMaxValue;
		}
		else
		{
			coefficients[i] = static_cast<Real>(1);
		}
	}

	return coefficients;
}


template <typename Real>
bool Mathematics
	::Approximate( const Ellipse2Coefficients<Real>& lhs,const Ellipse2Coefficients<Real>& rhs ,const Real epsilon)
{
	auto lhsCoefficients = lhs.GetCoefficients();
	auto rhsCoefficients = rhs.GetCoefficients();

	MATHEMATICS_ASSERTION_1(lhsCoefficients.size() == 6 && rhsCoefficients.size() == 6,"GetCoefficients返回的数组大小错误！");

	for(auto i = 0;i < 6;++i)
	{
		if (!Math<Real>::Approximate(lhsCoefficients[i], rhsCoefficients[i], epsilon))
		{
			return false;
		}		
	}

	return true;
}


#endif // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H

