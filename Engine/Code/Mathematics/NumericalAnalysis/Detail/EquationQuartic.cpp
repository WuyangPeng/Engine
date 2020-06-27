// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:00)

#include "Mathematics/MathematicsExport.h"

#include "EquationQuartic.h"
#include "EquationThrice.h"
#include "EquationSecondary.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

using std::complex;
using std::vector;

Mathematics::EquationQuartic
	::EquationQuartic(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
	:ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once },
	 m_Secondary{ secondary }, m_Thrice{ thrice }, m_Quartic{ quartic }
{
	Calculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EquationQuartic
	::~EquationQuartic()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationQuartic)

double Mathematics::EquationQuartic
	::Substitution(double value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value +
		   m_Secondary * Mathd::Square(value) +
		   m_Thrice * value * value * value +
		   m_Quartic * Mathd::Square(value) * Mathd::Square(value);
}

const Mathematics::EquationQuartic::Imaginary Mathematics::EquationQuartic
	::Substitution(const Imaginary& value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value +
		   m_Secondary * value * value +
		   m_Thrice * value * value * value +
		   m_Quartic * value * value * value * value;
}

double Mathematics::EquationQuartic
	::SubstitutionTangent(double solution) const
{
	return m_Once + solution * m_Secondary * 2.0 +
		   Mathd::Square(solution) * m_Thrice * 3.0 +
		   solution * solution * solution * m_Quartic * 4.0;
}

const Mathematics::EquationQuartic::Imaginary Mathematics::EquationQuartic
	::SubstitutionTangent(const Imaginary& solution) const
{
	return m_Once + solution * m_Secondary * 2.0 +
		   solution * solution *
		   m_Thrice * 3.0 +
		   solution * solution * solution *
		   m_Quartic * 4.0;
}

void Mathematics::EquationQuartic
	::Solving()
{
	// 消去三次项
	// p = -3a^2 / 8 + b
	// q = a^3 / 8 - ab / 2 + c
	// r = -3a^4 / 256 + ba^2 / 16 - ac / 4 + d
	auto p = CalculateP();
	auto q = CalculateQ();
	auto r = CalculateR();

	CalculateThriceEquation(p, q, r);
}

bool Mathematics::EquationQuartic
	::Predigest()
{
	// 常数项为零时，化解方程。
	if (Mathd::FAbs(m_Constant) <= GetEpsilon())
	{
		SetRealResult(0.0);
		EquationThrice equation{ m_Once,m_Secondary,m_Thrice,m_Quartic };
		AddResult(equation);

		return true;
	}

	// 四次项为零时，化解方程。
	if (Mathd::FAbs(m_Quartic) <= GetEpsilon())
	{
		EquationThrice equation{ m_Constant,m_Once,m_Secondary,m_Thrice };
		AddResult(equation);

		return true;
	}

	return false;
}

double Mathematics::EquationQuartic
	::CalculateP() const
{
	auto three = m_Thrice / m_Quartic;
	auto two = m_Secondary / m_Quartic;

	auto p = two - 3.0 * three * three / 8.0;

	return p;
}

double Mathematics::EquationQuartic
	::CalculateQ() const
{
	auto three = m_Thrice / m_Quartic;
	auto two = m_Secondary / m_Quartic;
	auto one = m_Once / m_Quartic;

	auto q = one - three * two / 2.0 + three * three * three / 8.0;
	return q;
}

double Mathematics::EquationQuartic
	::CalculateR() const
{
	auto three = m_Thrice / m_Quartic;
	auto two = m_Secondary / m_Quartic;
	auto one = m_Once / m_Quartic;
	auto zero = m_Constant / m_Quartic;

	auto r = zero - three * one / 4.0 +
			 three * three * two / 16.0 -
			 three * three * three * three * 3.0 / 256.0;
	return r;
}

void Mathematics::EquationQuartic
	::CalculateThriceEquation(double p, double q, double r)
{
	auto two = -p / 2.0;
	auto one = -r;
	auto zero = (4.0 * r * p - q * q) / 8.0;

	// 先求解一个三次方程。
	EquationThrice thrice{ zero,one,two,1.0 };

	MATHEMATICS_ASSERTION_1(thrice.IsRealResult(), "四次方程分解的三次方程无解！");

	for (auto iter = thrice.GetRealBegin(), end = thrice.GetRealEnd(); iter != end; ++iter)
	{
		CalculateResult(*iter, p, q, r);
	}
}

void Mathematics::EquationQuartic
	::CalculateResult(double solution, double p, double q, double r)
{
	auto x1 = 2.0 * solution - p;
	auto x0 = solution * solution - r;

	if (0.0 <= x1 && 0.0 <= x0)
	{
		auto x1sqrt = Mathd::Sqrt(x1);
		auto x0sqrt = Mathd::Sqrt(x0);

		if (0 <= q)
		{
			CalculateSecondaryEquation(solution, x0sqrt, x1sqrt);
		}
		else
		{
			CalculateSecondaryEquation(solution, -x0sqrt, x1sqrt);
		}
	}
}

void Mathematics::EquationQuartic
	::CalculateSecondaryEquation(double thriceSolution, double constant, double once)
{
	// 将四次方程分解为两个二次方程。
	auto minConstant = thriceSolution - constant;
	auto maxConstant = thriceSolution + constant;

	EquationSecondary firstEquation{ minConstant,once,1.0 };
	EquationSecondary secondEquation{ maxConstant,-once,1.0 };

	auto three = m_Thrice / m_Quartic;

	AddResult(firstEquation, -three / 4.0);
	AddResult(secondEquation, -three / 4.0);
}



