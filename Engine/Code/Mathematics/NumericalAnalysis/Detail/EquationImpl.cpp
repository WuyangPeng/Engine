// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:59)

#include "Mathematics/MathematicsExport.h"

#include "EquationImpl.h"
#include "EquationResult.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

Mathematics::EquationImpl
	::EquationImpl(double epsilon) noexcept
	:m_Result{}, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EquationImpl
	::~EquationImpl()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EquationImpl)

double Mathematics::EquationImpl
	::GetEpsilon() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Epsilon;
}

bool Mathematics::EquationImpl
	::IsRealResult() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.IsRealResult();
}

int Mathematics::EquationImpl
	::GetRealResultCount() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetRealResultCount();
}

int Mathematics::EquationImpl
	::GetImaginaryResultCount() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetImaginaryResultCount();
}

const Mathematics::EquationImpl::RealConstIterator Mathematics::EquationImpl
	::GetRealBegin() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetRealBegin();
}

const Mathematics::EquationImpl::RealConstIterator Mathematics::EquationImpl ::GetRealEnd() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetRealEnd();
}

const Mathematics::EquationImpl::ImaginaryConstIterator Mathematics::EquationImpl ::GetImaginaryBegin() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetImaginaryBegin();
}

const Mathematics::EquationImpl::ImaginaryConstIterator Mathematics::EquationImpl ::GetImaginaryEnd() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Result.GetImaginaryEnd();
}

// protected
void Mathematics::EquationImpl
	::SetRealResult(double result)
{
	m_Result.AddRealResult(result, m_Epsilon);
}

// protected
void Mathematics::EquationImpl
	::SetImaginaryResult(const Imaginary& result)
{
	m_Result.AddImaginaryResult(result, m_Epsilon);
}

// protected
void Mathematics::EquationImpl
	::AddResult(const EquationImpl& equation, double offset)
{
	AddRealResult(equation, offset);
	AddImaginaryResult(equation, offset);
}

// protected
void Mathematics::EquationImpl
	::Calculate()
{
	if (!Predigest())
	{
		Solving();
		Validate();
	}
}

// private
double Mathematics::EquationImpl
	::NewtonMethod(double solution) const
{
	auto amendSolution = solution;

	// 没有使用无限循环，避免无法退出！
	for (auto i = 0; i < sm_MaxTime; ++i)
	{
		const auto validateValue = Substitution(amendSolution);
		const auto derivative = SubstitutionTangent(amendSolution);

		if (Mathd::FAbs(derivative) <= m_Epsilon)
		{
			break;
		}

		const auto adjustedValue = validateValue / derivative;

		amendSolution -= adjustedValue;

		if (Mathd::FAbs(validateValue) <= m_Epsilon || Mathd::FAbs(derivative) <= m_Epsilon || Mathd::FAbs(adjustedValue) <= m_Epsilon)
		{
			break;
		}
	}

	return amendSolution;
}

// private
const Mathematics::EquationImpl::Imaginary Mathematics::EquationImpl
	::NewtonMethod(const Imaginary& solution) const
{
	auto amendSolution = solution;

	// 没有使用无限循环，避免无法退出！
	for (auto i = 0; i < sm_MaxTime; ++i)
	{
		const auto validateValue = Substitution(amendSolution);
		const auto derivative = SubstitutionTangent(amendSolution);
		const auto adjustedValue = validateValue / derivative;

		amendSolution -= adjustedValue;

		if ((Mathd::FAbs(validateValue.real()) <= m_Epsilon && Mathd::FAbs(validateValue.imag()) <= m_Epsilon) ||
			(Mathd::FAbs(derivative.real()) <= m_Epsilon && Mathd::FAbs(derivative.imag()) <= m_Epsilon) ||
			(Mathd::FAbs(adjustedValue.real()) <= m_Epsilon && Mathd::FAbs(adjustedValue.imag()) <= m_Epsilon))
		{
			break;
		}
	}

	return amendSolution;
}

// private
const Mathematics::EquationImpl::RealVector Mathematics::EquationImpl
	::NewRealResult() const
{
	RealVector newRealSolve;
	const auto end = GetRealEnd();
	for (auto iter = GetRealBegin(); iter != end; ++iter)
	{
		auto solve = *iter;
		solve = NewtonMethod(solve);
		newRealSolve.push_back(solve);
	}

	return newRealSolve;
}

// private
const Mathematics::EquationImpl::ImaginaryVector Mathematics::EquationImpl
	::NewImaginaryResult() const
{
	ImaginaryVector newImaginarySolve;

	const auto end = GetImaginaryEnd();
	for (auto iter = GetImaginaryBegin(); iter != end; ++iter)
	{
		auto solve = *iter;
		solve = NewtonMethod(solve);
		newImaginarySolve.push_back(solve);
	}

	return newImaginarySolve;
}

// private
void Mathematics::EquationImpl
	::CleanSolution() noexcept
{
	m_Result.CleanSolution();
}

// private
void Mathematics::EquationImpl
	::Validate()
{
	auto newRealSolve = NewRealResult();
	auto newImaginarySolve = NewImaginaryResult();

	CleanSolution();

	DisplaceRealResult(newRealSolve);
	DisplaceImaginaryResult(newImaginarySolve);
}

// private
void  Mathematics::EquationImpl
	::AddRealResult(const EquationImpl& equation, double offset)
{
	const auto end = equation.GetRealEnd();
	for (auto iter = equation.GetRealBegin(); iter != end; ++iter)
	{
		const auto result = *iter + offset;

		SetRealResult(result);
	}
}

// private
void  Mathematics::EquationImpl
	::AddImaginaryResult(const EquationImpl& equation, double offset)
{
	const auto end = equation.GetImaginaryEnd();
	for (auto iter = equation.GetImaginaryBegin(); iter != end; ++iter)
	{
		const auto result = *iter + offset;

		SetImaginaryResult(result);
	}
}

// private
void Mathematics::EquationImpl
	::DisplaceRealResult(const RealVector& result)
{
	for (const auto& value : result)
	{
		SetRealResult(value);
	}
}

// private
void Mathematics::EquationImpl
	::DisplaceImaginaryResult(const ImaginaryVector& result)
{
	for (const auto& value : result)
	{
		SetImaginaryResult(value);
	}
}

void Mathematics::EquationImpl
	::SortResult()
{
	m_Result.SortResult();
}