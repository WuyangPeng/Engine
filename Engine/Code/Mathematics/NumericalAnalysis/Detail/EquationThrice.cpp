// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 13:02)

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

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationThrice)

double Mathematics::EquationThrice
	::Substitution(double value) const noexcept
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
	::SubstitutionTangent(double solution) const noexcept
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
	// �� t = x - a / 3
	// ȥ��������õ�����x^3 + px + q = 0
	// p = -a^2/3 + b
	// q = 2a^3/27 - ab/3 +c
	// p' = p / 3 ,q' = q / 2
	const auto pThird = CalculatePThird();
	const auto qHalf = CalculateQHalf();

	// ���ʽ D' = p'^3 + q'^2
	const auto discriminant = CalculateDiscriminant(pThird, qHalf);

	CalculateResult(pThird, qHalf, discriminant);
}

bool Mathematics::EquationThrice
	::Predigest()
{
	// ������Ϊ��ʱ�����ⷽ�̡�
	if (Mathd::FAbs(m_Constant) <= GetEpsilon())
	{
		SetRealResult(0.0);
		EquationSecondary equation{ m_Once,m_Secondary,m_Thrice };
		AddResult(equation);

		return true;
	}

	// ������Ϊ��ʱ�����ⷽ�̡�
	if (Mathd::FAbs(m_Thrice) <= GetEpsilon())
	{
		EquationSecondary equation{ m_Constant,m_Once,m_Secondary };
		AddResult(equation);

		return true;
	}

	return false;
}

 


double Mathematics::EquationThrice
	::CalculatePThird() const noexcept
{
	const auto two = m_Secondary / m_Thrice;
	const auto one = m_Once / m_Thrice;

	const auto p = one - two * two / 3.0;
	const auto pThird = p / 3.0;

	return pThird;
}

double Mathematics::EquationThrice
	::CalculateQHalf() const noexcept
{
	const auto two = m_Secondary / m_Thrice;
	const auto one = m_Once / m_Thrice;
	const auto zero = m_Constant / m_Thrice;

	const auto q = zero - two * one / 3.0 + two * two * two / 27.0 * 2.0;
	const auto qHalf = q / 2.0;

	return qHalf;
}

void Mathematics::EquationThrice
	::CalculateResult(double pThird, double qHalf, double discriminant)
{
	// ���̽������������Ϊ��
	// x1 = r     + s
	// x2 = r��   + s��^2
	// x3 = r��^2 + s��
	// ����
	// ��   = -0.5 + i(sqrt(3)/2)
	// ��^2 = -0.5 - i(sqrt(3)/2)
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
	const auto two = m_Secondary / m_Thrice;

	const auto discriminantSqrt = Mathd::Sqrt(discriminant);
	const auto rCube = -qHalf + discriminantSqrt;
	const auto sCube = -qHalf - discriminantSqrt;

	const auto r = Mathd::CubeRoot(rCube);
	const auto s = Mathd::CubeRoot(sCube);

	// ��ʵ����
	const auto realResult = r + s - two / 3.0;

	SetRealResult(realResult);

	// ��������
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
	const auto two = m_Secondary / m_Thrice;

	const auto r = Mathd::CubeRoot(qHalf);

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
	const auto two = m_Secondary / m_Thrice;

	// ���潫x = 2mcos�ȴ��뷽��
	// ������4cos^3(��) - 3cos�� = cos(3��)������̵Ľ⡣
	const auto middleAngle = Mathd::ACos(-qHalf / Mathd::Sqrt(-pThird * pThird * pThird)) / 3.0;
	const auto leastAngle = middleAngle - 2.0 * Mathd::sm_PI / 3.0;
	const auto mostAngle = middleAngle + 2.0 * Mathd::sm_PI / 3.0;
	const auto prefix = 2.0 * Mathd::Sqrt(-pThird);

	const auto leastAngleRealResult = prefix * Mathd::Cos(leastAngle) - two / 3.0;
	const auto middleAngleRealResult = prefix * Mathd::Cos(middleAngle) - two / 3.0;
	const auto mostAngleRealResult = prefix * Mathd::Cos(mostAngle) - two / 3.0;

	SetRealResult(leastAngleRealResult);
	SetRealResult(middleAngleRealResult);
	SetRealResult(mostAngleRealResult);

	SortResult();
}


