// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 09:54)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H

#include "Ellipsoid3Coefficients.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>
	::Ellipsoid3Coefficients( const Matrix3& matrix, const Vector3D& vector,Real constants )
	:m_Coefficients{ constants,vector[0] ,vector[1] ,vector[2],matrix(0,0),
					 matrix(0,1) * static_cast<Real>(2),matrix(0,2) * static_cast<Real>(2),matrix(1,1),matrix(1,2) * static_cast<Real>(2),matrix(2,2) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>
	::Ellipsoid3Coefficients( const std::vector<Real>& coefficient )
	:m_Coefficients{ coefficient }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipsoid3Coefficients<Real>
	::IsValid() const noexcept
{
	if(m_Coefficients.size() == static_cast<size_t>(GetCoefficientsSize()))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const  Mathematics::Ellipsoid3Coefficients<Real>::Matrix3 Mathematics::Ellipsoid3Coefficients<Real>
	::GetMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Matrix3{ m_Coefficients[4],
				    static_cast<Real>(0.5) * m_Coefficients[5],
				    static_cast<Real>(0.5) * m_Coefficients[6],
				    static_cast<Real>(0.5) * m_Coefficients[5],
				    m_Coefficients[7],
				    static_cast<Real>(0.5) * m_Coefficients[8],
				    static_cast<Real>(0.5) * m_Coefficients[6],
				    static_cast<Real>(0.5) * m_Coefficients[8],
				    m_Coefficients[9] };
}

template <typename Real>
typename const  Mathematics::Ellipsoid3Coefficients<Real>::Vector3D Mathematics::Ellipsoid3Coefficients<Real>
	::GetVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Vector3D{ m_Coefficients[1],m_Coefficients[2],m_Coefficients[3] };
}

template <typename Real>
Real Mathematics::Ellipsoid3Coefficients<Real>
	::GetConstants() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Coefficients[0];
}

template <typename Real>
const std::vector<Real> Mathematics::Ellipsoid3Coefficients<Real>
	::GetCoefficients() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	std::vector<Real> coefficients{ m_Coefficients };

	// 安排x0^2或x1^2或x2^2系数之一是1。
	auto maxValue = Math<Real>::FAbs(coefficients[4]);
	int maxIndex{ 4 };
	auto absValue = Math<Real>::FAbs(coefficients[7]);
	if (maxValue < absValue)
	{
		maxValue = absValue;
		maxIndex = 7;
	}
	absValue = Math<Real>::FAbs(coefficients[9]);
	if (maxValue < absValue)
	{
		maxValue = absValue;
		maxIndex = 9;
	}

	auto invMaxValue = static_cast<Real>(1) / maxValue;
	for (auto i = 0; i < GetCoefficientsSize(); ++i)
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

// static
template <typename Real>
int Mathematics::Ellipsoid3Coefficients<Real>
	::GetCoefficientsSize()
{
	return 10;
}

template <typename Real>
bool Mathematics
	::Approximate( const Ellipsoid3Coefficients<Real>& lhs,const Ellipsoid3Coefficients<Real>& rhs ,const Real epsilon)
{
	auto lhsCoefficients = lhs.GetCoefficients();
	auto rhsCoefficients = rhs.GetCoefficients();

	MATHEMATICS_ASSERTION_1(lhsCoefficients.size() == boost::numeric_cast<size_t>(lhs.GetCoefficientsSize()) &&
							rhsCoefficients.size() == boost::numeric_cast<size_t>(rhs.GetCoefficientsSize()),
							"GetCoefficients返回的数组大小错误！");

	for(auto i = 0;i < Ellipsoid3Coefficients<Real>::GetCoefficientsSize();++i)
	{
		if (!Math<Real>::Approximate(lhsCoefficients[i], rhsCoefficients[i], epsilon))
		{
			return false;
		}			
	}

	return true;
}


#endif // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H

