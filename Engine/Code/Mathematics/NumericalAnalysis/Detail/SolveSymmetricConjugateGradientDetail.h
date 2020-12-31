///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 18:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H

#include "SolveSymmetricConjugateGradient.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrix.h"

template <typename Real, template <typename> class Matrix>
Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::SolveSymmetricConjugateGradient(const MatrixType& matrix, const RealContainer& input, Real zeroTolerance)
    : m_ZeroTolerance{ zeroTolerance },
      m_Matrix{ matrix },
      m_Size{ matrix.GetRowsNumber() },
      m_InputAmend1{ input },
      m_InputAmend2{ m_InputAmend1 },
      m_Product(m_Size),
      m_Normal{},
      m_Output(m_Size),
      m_Dot0{},
      m_Dot1{},
      m_Alpha{}
{
    CalculateNormal(input);
    FirstIteration();
    RemainingIterations();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::CalculateNormal(const RealContainer& input) noexcept
{
    m_Normal = Dot(input, input);
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::FirstIteration()
{
    // 第一次迭代。
    m_Dot0 = Dot(m_InputAmend1, m_InputAmend1);
    Multiply();
    auto inputAmend2Dot = Dot(m_InputAmend2, m_Product);

    m_Alpha = m_Dot0 / inputAmend2Dot;
    UpdateOutput();
    UpdateAmend1();
    m_Dot1 = Dot(m_InputAmend1, m_InputAmend1);
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::RemainingIterations()
{
    // 剩余的迭代。
    constexpr auto max = 1024;
    auto secondRoot = Math<Real>::Sqrt(m_Normal);

    for (auto i = 1; i < max; ++i)
    {
        auto firstRoot = Math<Real>::Sqrt(m_Dot1);
        if (firstRoot <= m_ZeroTolerance * secondRoot)
        {
            return;
        }

        UpdateAmend2();
        Multiply();

        auto inputSecondAmendDot = Dot(m_InputAmend2, m_Product);

        m_Alpha = m_Dot1 / inputSecondAmendDot;
        UpdateOutput();
        UpdateAmend1();
        m_Dot0 = m_Dot1;
        m_Dot1 = Dot(m_InputAmend1, m_InputAmend1);
    }

    THROW_EXCEPTION(SYSTEM_TEXT("循环超出次数！"s));
}

// private
template <typename Real, template <typename> class Matrix>
Real Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::Dot(const RealContainer& lhs, const RealContainer& rhs) const noexcept
{
    auto dot = Math<Real>::GetValue(0);
    for (auto i = 0; i < m_Size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        dot += lhs[i] * rhs[i];
#include STSTEM_WARNING_POP
    }
    return dot;
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::Multiply()
{
    m_Product.assign(m_Size, Math<Real>::GetValue(0));

    for (auto row = 0; row < m_Size; ++row)
    {
        for (auto col = 0; col < m_Size; ++col)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Product[row] += m_Matrix(row, col) * m_InputAmend2[col];
#include STSTEM_WARNING_POP
        }
    }
}

// private
template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>::Multiply();

// private
template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>::Multiply();

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateOutput() noexcept
{
    for (auto i = 0; i < m_Size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Output[i] += m_Alpha * m_InputAmend2[i];
#include STSTEM_WARNING_POP
    }
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateAmend1() noexcept
{
    for (auto i = 0; i < m_Size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_InputAmend1[i] -= m_Alpha * m_Product[i];
#include STSTEM_WARNING_POP
    }
}

// private
template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateAmend2() noexcept
{
    auto beta = m_Dot1 / m_Dot0;

    for (auto i = 0; i < m_Size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_InputAmend2[i] = m_InputAmend1[i] + beta * m_InputAmend2[i];
#include STSTEM_WARNING_POP
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Matrix>
bool Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::IsValid() const noexcept
{
    try
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
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Matrix>
typename Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::RealContainer Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::GetResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
