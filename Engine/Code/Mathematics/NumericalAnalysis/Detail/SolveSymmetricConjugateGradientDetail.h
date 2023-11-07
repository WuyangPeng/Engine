///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:41)

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
    : zeroTolerance{ zeroTolerance },
      matrix{ matrix },
      size{ matrix.GetRowsNumber() },
      inputAmend1{ input },
      inputAmend2{ inputAmend1 },
      product(size),
      normal{},
      output(size),
      dot0{},
      dot1{},
      alpha{}
{
    CalculateNormal(input);
    FirstIteration();
    RemainingIterations();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::CalculateNormal(const RealContainer& input) noexcept
{
    normal = Dot(input, input);
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::FirstIteration()
{
    // 第一次迭代。
    dot0 = Dot(inputAmend1, inputAmend1);
    Multiply();
    const auto inputAmend2Dot = Dot(inputAmend2, product);

    alpha = dot0 / inputAmend2Dot;
    UpdateOutput();
    UpdateAmend1();
    dot1 = Dot(inputAmend1, inputAmend1);
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::RemainingIterations()
{
    // 剩余的迭代。
    constexpr auto max = 1024;
    auto secondRoot = Math<Real>::Sqrt(normal);

    for (auto i = 1; i < max; ++i)
    {
        const auto firstRoot = Math<Real>::Sqrt(dot1);
        if (firstRoot <= zeroTolerance * secondRoot)
        {
            return;
        }

        UpdateAmend2();
        Multiply();

        const auto inputSecondAmendDot = Dot(inputAmend2, product);

        alpha = dot1 / inputSecondAmendDot;
        UpdateOutput();
        UpdateAmend1();
        dot0 = dot1;
        dot1 = Dot(inputAmend1, inputAmend1);
    }

    THROW_EXCEPTION(SYSTEM_TEXT("循环超出次数！"s))
}

template <typename Real, template <typename> class Matrix>
Real Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::Dot(const RealContainer& lhs, const RealContainer& rhs) const noexcept
{
    Real dot{};
    for (auto i = 0; i < size; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        dot += lhs[i] * rhs[i];

#include SYSTEM_WARNING_POP
    }
    return dot;
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::Multiply()
{
    product.assign(size, Math<Real>::GetValue(0));

    for (auto row = 0; row < size; ++row)
    {
        for (auto col = 0; col < size; ++col)
        {
            product.at(row) += matrix(row, col) * inputAmend2.at(col);
        }
    }
}

template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>::Multiply();

template <>
MATHEMATICS_DEFAULT_DECLARE void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>::Multiply();

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateOutput() noexcept
{
    for (auto i = 0; i < size; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        output[i] += alpha * inputAmend2[i];

#include SYSTEM_WARNING_POP
    }
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateAmend1() noexcept
{
    for (auto i = 0; i < size; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        inputAmend1[i] -= alpha * product[i];

#include SYSTEM_WARNING_POP
    }
}

template <typename Real, template <typename> class Matrix>
void Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::UpdateAmend2() noexcept
{
    auto beta = dot1 / dot0;

    for (auto i = 0; i < size; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        inputAmend2[i] = inputAmend1[i] + beta * inputAmend2[i];

#include SYSTEM_WARNING_POP
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Matrix>
bool Mathematics::SolveSymmetricConjugateGradient<Real, Matrix>::IsValid() const noexcept
{
    try
    {
        if (matrix.GetRowsNumber() == matrix.GetColumnsNumber() && Math<Real>::GetValue(0) <= zeroTolerance)
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

    return output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
