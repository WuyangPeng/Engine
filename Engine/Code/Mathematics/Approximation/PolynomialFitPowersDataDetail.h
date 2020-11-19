// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 14:56)

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

	if (0 <= index && index < Size - 1)
	{
		return m_MaxPower[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetMin(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < Size)
	{
		return m_Min[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetMax(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < Size)
	{
		return m_Max[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real, int S>
Real Mathematics::PolynomialFitPowersData<Real, S>
	::GetScale(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < Size)
	{
		return m_Scale[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
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
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Coefficients.size()), "索引越界\n");

	return m_Coefficients[index];
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>
	::SetMaxPower(int index, int power)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (0 <= index && index < Size - 1)
	{
		m_MaxPower[index] = power;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real, int S>
void Mathematics::PolynomialFitPowersData<Real, S>
	::SetScale(int index, Real scale)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (0 <= index && index < Size)
	{
		m_Scale[index] = scale;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}

	if (index == Size - 1)
	{
		m_InvTwoWScale =  Math::GetRational(1,2) / m_Scale[index];
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