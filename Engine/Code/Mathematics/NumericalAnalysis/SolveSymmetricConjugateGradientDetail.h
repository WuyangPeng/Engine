// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 17:27) 

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H

#include "SolveSymmetricConjugateGradient.h"
#include "SparseMatrix.h"
#include "System/Helper/UnicodeUsing.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"  
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Matrix>
Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::SolveSymmetricConjugateGradient(const MatrixType& matrix, const Real* inputVector, Real zeroTolerance)
	: m_ZeroTolerance{ zeroTolerance }, m_Matrix{ matrix }, m_Size{ matrix.GetRowsNumber() },
	  m_InputFirstAmend{ inputVector, inputVector + m_Size }, m_InputSecondAmend{ m_InputFirstAmend }, m_Product(m_Size),
	  m_Normal{}, m_Output(m_Size), m_FirstDot{}, m_SecondDot{}, m_Alpha{}
{
	CalculateNormal(inputVector);
	FirstIteration();
	RemainingIterations();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::CalculateNormal(const Real* inputVector)
{
	m_Normal = Dot(inputVector, inputVector);
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::FirstIteration()
{
	// 第一次迭代。
	m_FirstDot = Dot(&m_InputFirstAmend[0], &m_InputFirstAmend[0]);
	Multiply();
	auto inputSecondAmendDot = Dot(&m_InputSecondAmend[0], &m_Product[0]);

	m_Alpha = m_FirstDot / inputSecondAmendDot;
	UpdateOutput();
	UpdateFirstAmend();
	m_SecondDot = Dot(&m_InputFirstAmend[0], &m_InputFirstAmend[0]);
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::RemainingIterations()
{
	// 剩余的迭代。
	constexpr auto max = 1024;
	auto secondRoot = Math<Real>::Sqrt(m_Normal);

	for (auto i = 1; i < max; ++i)
	{
		auto firstRoot = Math<Real>::Sqrt(m_SecondDot);
		if (firstRoot <= m_ZeroTolerance * secondRoot)
		{
			return;
		}

		UpdateSecondAmend();
		Multiply();

		auto inputSecondAmendDot = Dot(&m_InputSecondAmend[0], &m_Product[0]);

		m_Alpha = m_SecondDot / inputSecondAmendDot;
		UpdateOutput();
		UpdateFirstAmend();
		m_FirstDot = m_SecondDot;
		m_SecondDot = Dot(&m_InputFirstAmend[0], &m_InputFirstAmend[0]);
	}

	THROW_EXCEPTION(SYSTEM_TEXT("循环超出次数！"));
}

// private
template <typename Real, template <typename> class Matrix>
Real Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::Dot(const Real* lhs, const Real* rhs) const
{
	auto dot = Math<Real>::GetValue(0);
	for (auto i = 0; i < m_Size; ++i)
	{
		dot += lhs[i] * rhs[i];
	}
	return dot;
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::Multiply()
{
	m_Product.assign(m_Size, Math<Real>::GetValue(0));

	for (auto row = 0; row < m_Size; ++row)
	{
		for (auto col = 0; col < m_Size; ++col)
		{
			m_Product[row] += m_Matrix(row, col) * m_InputSecondAmend[col];
		}
	}
}

// private
template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>
	::Multiply();

// private
template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>
	::Multiply();

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::UpdateOutput()
{
	for (auto i = 0; i < m_Size; ++i)
	{
		m_Output[i] += m_Alpha * m_InputSecondAmend[i];
	}
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::UpdateFirstAmend()
{
	for (auto i = 0; i < m_Size; ++i)
	{
		m_InputFirstAmend[i] -= m_Alpha * m_Product[i];
	}
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::UpdateSecondAmend()
{
	auto beta = m_SecondDot / m_FirstDot;

	for (auto i = 0; i < m_Size; ++i)
	{
		m_InputSecondAmend[i] = m_InputFirstAmend[i] + beta * m_InputSecondAmend[i];
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Matrix>
bool Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::IsValid() const noexcept
{
	if (m_Matrix.GetRowsNumber() == m_Matrix.GetColumnsNumber() && Math<Real>::GetValue(0) <= m_ZeroTolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Matrix>
typename const Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::OutputConstIterator	Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::GetBegin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_Output.begin() };
}

template <typename Real, template <typename> class Matrix>
typename const Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::OutputConstIterator Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>
	::GetEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_Output.end() };
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
