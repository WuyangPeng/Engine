// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:43)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H

#include "PolynomialFitPowersData.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real, int S>
Mathematics::PolynomialFitPowersData<Real, S>
	::PolynomialFitPowersData(int numPowers)
	:m_MaxPower{}, m_Min{}, m_Max{}, m_Scale{}, m_InvTwoWScale{}, m_Coefficients(numPowers), m_Solved{ false }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, int S>
bool Mathematics::PolynomialFitPowersData<Real, S>
	::IsValid() const noexcept
{
	if (!m_Coefficients.empty())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real, int S>
bool Mathematics::PolynomialFitPowersData<Real, S>
	::IsSolveSucceed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Solved;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>
	::GetSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Size;
}

template <typename Real, int S>
int Mathematics::PolynomialFitPowersData<Real, S>
	::GetMaxPower(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size - 1, "索引越界\n");

	return m_MaxPower[index];
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetMin(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size, "索引越界\n");

	return m_Min[index];
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetMax(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size, "索引越界\n");

	return m_Max[index];
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetScale(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size, "索引越界\n");

	return m_Scale[index];
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetInvTwoWScale() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_InvTwoWScale;
}


template <typename Real, int S>
const std::vector<Real> Mathematics::PolynomialFitPowersData<Real, S>
	::GetCoefficients() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Coefficients;
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetCoefficients(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Coefficients.size()), "索引越界\n");

	return m_Coefficients[index];
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>
	::SetMaxPower(int index,int power)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size - 1, "索引越界\n");

	m_MaxPower[index] = power;
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>
	::SetScale(int index, Real scale)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < Size, "索引越界\n");

	m_Scale[index] = scale;

	if (index == Size - 1)
	{
		m_InvTwoWScale = static_cast<Real>(0.5) / m_Scale[index];
	}
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>
	::Solve(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	try
	{
		auto value = vector.GetValue();

		LinearSystem<Real>{}.Solve(matrix, &value[0], &m_Coefficients[0]);

		m_Solved = true;
	}
	catch (CoreTools::Error& error)
	{
		m_Solved = false;

		LOG_SINGLETON_APPENDER(Info, CoreTools)
			<< SYSTEM_TEXT("求解线性系统失败\n")
			<< error
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

#endif // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT_POWERS_DATA_DETAIL_H