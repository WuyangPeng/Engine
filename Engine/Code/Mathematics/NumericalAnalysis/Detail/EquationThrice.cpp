// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:02)

#include "Mathematics/MathematicsExport.h"

#include "EquationThrice.h"
#include "EquationSecondary.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

using std::swap;

Mathematics::EquationThrice
	::EquationThrice(double constant, double once, double secondary, double thrice, double epsilon)
	:ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once }, m_Secondary{ secondary }, m_Thrice{ thrice }
{
	Calculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EquationThrice
	::~EquationThrice()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationThrice)

double Mathematics::EquationThrice
	::Substitution(double value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value +
		   m_Secondary * Mathd::Square(value) +
		   m_Thrice * value * value * value;
}

const Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice
	::Substitution(const Imaginary& value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + m_Once * value +
		   m_Secondary * value * value +
		   m_Thrice * value * value * value;
}

double Mathematics::EquationThrice
	::SubstitutionTangent(double solution) const
{
	return m_Once + solution * m_Secondary * 2.0 +
		   Mathd::Square(solution) * m_Thrice * 3.0;
}

const Mathematics::EquationThrice::Imaginary Mathematics::EquationThrice
	::SubstitutionTangent(const Imaginary& solution) const
{
	return m_Once + solution * m_Secondary * 2.0 +
		   solution * solution *
		   m_Thrice * 3.0;
}

void  Mathematics::EquationThrice
	::Solving()
{
	// 另 t = x - a / 3
	// 去掉二次项，得到方程x^3 + px + q = 0
	// p = -a^2/3 + b
	// q = 2a^3/27 - ab/3 +c
	// p' = p / 3 ,q' = q / 2
	auto pThird = CalculatePThird();
	auto qHalf = CalculateQHalf();

	// 差别式 D' = p'^3 + q'^2
	auto discriminant = CalculateDiscriminant(pThird, qHalf);

	CalculateResult(pThird, qHalf, discriminant);
}

bool Mathematics::EquationThrice
	::Predigest()
{
	// 常数项为零时，化解方程。
	if (Mathd::FAbs(m_Constant) <= GetEpsilon())
	{
		SetRealResult(0.0);
		EquationSecondary equation{ m_Once,m_Secondary,m_Thrice };
		AddResult(equation);

		return true;
	}

	// 三次项为零时，化解方程。
	if (Mathd::FAbs(m_Thrice) <= GetEpsilon())
	{
		EquationSecondary equation{ m_Constant,m_Once,m_Secondary };
		AddResult(equation);

		return true;
	}

	return false;
}

// static
double Mathematics::EquationThrice
	::CalculateDiscriminant(double pThird, double qHalf)
{
	return qHalf * qHalf + pThird * pThird * pThird;
}

double Mathematics::EquationThrice
	::CalculatePThird() const
{
	auto two = m_Secondary / m_Thrice;
	auto one = m_Once / m_Thrice;

	auto p = one - two * two / 3.0;
	auto pThird = p / 3.0;

	return pThird;
}

double Mathematics::EquationThrice
	::CalculateQHalf() const
{
	auto two = m_Secondary / m_Thrice;
	auto one = m_Once / m_Thrice;
	auto zero = m_Constant / m_Thrice;

	auto q = zero - two * one / 3.0 + two * two * two / 27.0 * 2.0;
	auto qHalf = q / 2.0;

	return qHalf;
}

void Mathematics::EquationThrice
	::CalculateResult(double pThird, double qHalf, double discriminant)
{
	// 方程解的三个复数根为：
	// x1 = r     + s
	// x2 = rρ   + sρ^2
	// x3 = rρ^2 + sρ
	// 其中
	// ρ   = -0.5 + i(sqrt(3)/2)
	// ρ^2 = -0.5 - i(sqrt(3)/2)
	if (Mathd::FAbs(discriminant) <= GetEpsilon())
		CalculateResultDiscriminantIsZero(qHalf);
	else if (0.0 < discriminant)
		CalculateResultDiscriminantIsPlus(qHalf, discriminant);
	else
		CalculateResultDiscriminantIsNegative(pThird, qHalf);
}

void Mathematics::EquationThrice
	::CalculateResultDiscriminantIsPlus(double qHalf, double discriminant)
{
	auto two = m_Secondary / m_Thrice;

	auto discriminantSqrt = Mathd::Sqrt(discriminant);
	auto rCube = -qHalf + discriminantSqrt;
	auto sCube = -qHalf - discriminantSqrt;

	auto r = Mathd::CubeRoot(rCube);
	auto s = Mathd::CubeRoot(sCube);

	// 求实数根
	auto realResult = r + s - two / 3.0;

	SetRealResult(realResult);

	// 求虚数根
	const Imaginary density{ -0.5, Mathd::Sqrt(3.0) / 2.0 };
	const Imaginary densitySquare{ -0.5, -Mathd::Sqrt(3.0) / 2.0 };

	auto minImaginaryResult = density * r + densitySquare * s - two / 3.0;
	auto maxImaginaryResult = density * s + densitySquare * r - two / 3.0;

	if (0 < minImaginaryResult.imag())
	{
		swap(minImaginaryResult, maxImaginaryResult);
	}

	SetImaginaryResult(minImaginaryResult);
	SetImaginaryResult(maxImaginaryResult);
}

void Mathematics::EquationThrice
	::CalculateResultDiscriminantIsZero(double qHalf)
{
	auto two = m_Secondary / m_Thrice;

	auto r = Mathd::CubeRoot(qHalf);

	auto minRealResult = 2 * r - two / 3.0;
	auto maxRealResult = -r - two / 3.0;

	if (maxRealResult < minRealResult)
	{
		swap(minRealResult, maxRealResult);
	}

	SetRealResult(minRealResult);
	SetRealResult(maxRealResult);
}

void Mathematics::EquationThrice
	::CalculateResultDiscriminantIsNegative(double pThird, double qHalf)
{
	auto two = m_Secondary / m_Thrice;

	// 下面将x = 2mcosθ代入方程
	// 并根据4cos^3(θ) - 3cosθ = cos(3θ)求出方程的解。
	auto middleAngle = Mathd::ACos(-qHalf / Mathd::Sqrt(-pThird * pThird * pThird)) / 3.0;
	auto leastAngle = middleAngle - 2.0 * Mathd::sm_PI / 3.0;
	auto mostAngle = middleAngle + 2.0 * Mathd::sm_PI / 3.0;
	auto prefix = 2.0 * Mathd::Sqrt(-pThird);

	auto leastAngleRealResult = prefix * Mathd::Cos(leastAngle) - two / 3.0;
	auto middleAngleRealResult = prefix * Mathd::Cos(middleAngle) - two / 3.0;
	auto mostAngleRealResult = prefix * Mathd::Cos(mostAngle) - two / 3.0;

	SetRealResult(leastAngleRealResult);
	SetRealResult(middleAngleRealResult);
	SetRealResult(mostAngleRealResult);

	SortResult();
}


