// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:02)

#include "Mathematics/MathematicsExport.h"

#include "EquationSecondary.h"
#include "EquationOnce.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::EquationSecondary
	::EquationSecondary(double constant, double once, double secondary, double epsilon)  
	:ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once }, m_Secondary{ secondary }
{
	Calculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationSecondary)

double Mathematics::EquationSecondary
	::Substitution(double value) const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value + m_Secondary * value * value;
}

const Mathematics::EquationSecondary::Imaginary Mathematics::EquationSecondary
	::Substitution(const Imaginary& value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value + m_Secondary * value * value;
}

double Mathematics::EquationSecondary
	::SubstitutionTangent(double solution) const noexcept
{
	return m_Once + solution * m_Secondary * 2.0;
}

const Mathematics::EquationSecondary::Imaginary Mathematics::EquationSecondary
	::SubstitutionTangent(const Imaginary& solution) const
{
	return m_Once + solution * m_Secondary * 2.0;
}

void Mathematics::EquationSecondary
	::Solving()
{
	const auto discriminant = CalculateDiscriminant();
	const auto lhsTemporarily = CalculateLhs();

	CalculateResult(lhsTemporarily, discriminant);
}

bool Mathematics::EquationSecondary
	::Predigest()
{
	// 求出一个解为0，并简化为一次方程
	if (DoubleMath::FAbs(m_Constant) <= GetEpsilon())
	{
		SetRealResult(0.0);
		EquationOnce equation{ m_Once,m_Secondary };
		AddResult(equation);

		return true;
	}

	// 简化为一次方程
	if (DoubleMath::FAbs(m_Secondary) <= GetEpsilon())
	{
		EquationOnce equation{ m_Constant,m_Once };
		AddResult(equation);

		return true;
	}

	return false;
}

double Mathematics::EquationSecondary
	::CalculateDiscriminant() const noexcept
{
	// 计算b^2 - 4ac
	return  -m_Secondary * m_Constant * 4.0 + m_Once * m_Once;
}

double Mathematics::EquationSecondary
	::CalculateLhs() const noexcept
{
	// 计算-b / 2a
	return -m_Once / m_Secondary / 2.0;
}

void Mathematics::EquationSecondary
	::CalculateResult(double lhs, double discriminant)
{
	if (DoubleMath::FAbs(discriminant) <= GetEpsilon())
		CalculateResultDiscriminantIsZero(lhs);
	else if (0.0 < discriminant)
		CalculateResultDiscriminantIsPlus(lhs, discriminant);
	else
		CalculateResultDiscriminantIsNegative(lhs, discriminant);
}

void Mathematics::EquationSecondary
	::CalculateResultDiscriminantIsPlus(double lhs, double discriminant)
{
	// 计算sqrt(discriminant) / 2a
	auto rhs = DoubleMath::Sqrt(discriminant) / m_Secondary / 2.0;

	const auto minResult = lhs - rhs;
	const auto maxResult = lhs + rhs;

	SetRealResult(minResult);
	SetRealResult(maxResult);
}

void Mathematics::EquationSecondary
	::CalculateResultDiscriminantIsZero(double lhs)
{
	SetRealResult(lhs);
}

void Mathematics::EquationSecondary
	::CalculateResultDiscriminantIsNegative(double lhs, double discriminant)
{
	// 计算sqrt(-discriminant) / 2a
	auto rhs = DoubleMath::Sqrt(-discriminant) / m_Secondary / 2.0;

	SetImaginaryResult(Imaginary{ lhs, -rhs });
	SetImaginaryResult(Imaginary{ lhs, rhs });
}

