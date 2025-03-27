/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_DETAIL_H

#include "CholeskyDecompositionDetail.h"
#include "GaussNewtonMinimizer.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::GaussNewtonMinimizer<Real>::GaussNewtonMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JFunction inJFunction)
    : numPDimensions{ numPDimensions },
      numFDimensions{ numFDimensions },
      fFunction{ std::move(inFFunction) },
      jFunction{ std::move(inJFunction) },
      jPlusFunction{},
      f{ numFDimensions },
      j{ numFDimensions, numPDimensions },
      jtj{ numPDimensions, numPDimensions },
      negJtf{ numPDimensions },
      decomposer{ numPDimensions },
      useJFunction{ true }
{
    if (!(numPDimensions > 0 && numFDimensions > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的维度"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::GaussNewtonMinimizer<Real>::GaussNewtonMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JPlusFunction inJPlusFunction)
    : numPDimensions{ numPDimensions },
      numFDimensions{ numFDimensions },
      fFunction{ std::move(inFFunction) },
      jFunction{},
      jPlusFunction{ std::move(inJPlusFunction) },
      f{ numFDimensions },
      j{ numFDimensions, numPDimensions },
      jtj{ numPDimensions, numPDimensions },
      negJtf{ numPDimensions },
      decomposer{ numPDimensions },
      useJFunction{ false }
{
    if (!(numPDimensions > 0 && numFDimensions > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的维度"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::GaussNewtonMinimizer<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::GaussNewtonMinimizer<Real>::GetNumPDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numPDimensions;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::GaussNewtonMinimizer<Real>::GetNumFDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numFDimensions;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::GaussNewtonMinimizer<Real>::GaussNewtonMinimizerResultType Mathematics::GaussNewtonMinimizer<Real>::operator()(const DVector& p0, int maxIterations, Real updateLengthTolerance, Real errorDifferenceTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    GaussNewtonMinimizerResultType result{};
    result.SetMinLocation(p0);
    result.SetMinError(std::numeric_limits<Real>::max());
    result.SetMinErrorDifference(std::numeric_limits<Real>::max());
    result.SetMinUpdateLength(Real{});
    result.SetNumIterations(0);
    result.SetConverged(false);

    /// 作为一个简单的预防措施，确保公差为非负。
    updateLengthTolerance = std::max(updateLengthTolerance, Real{});
    errorDifferenceTolerance = std::max(errorDifferenceTolerance, Real{});

    /// 计算初始误差。
    fFunction(p0, f);
    result.SetMinError(Dot(f, f));

    /// 进行高斯-牛顿迭代。
    auto pCurrent = p0;
    for (result.SetNumIterations(1); result.GetNumIterations() <= maxIterations; result.AddNumIterations())
    {
        ComputeLinearSystemInputs(pCurrent);
        if (!decomposer.Factor(jtj))
        {
            /// 矩阵jtj是正半定的，所以当jtj具有零特征值时，
            /// 可能会发生故障，在这种情况下jtj不可逆。
            /// 无论如何都要生成迭代，也许使用梯度下降？
            return result;
        }
        negJtf = decomposer.SolveLower(jtj);
        negJtf = decomposer.SolveUpper(jtj);

        auto pNext = pCurrent + negJtf;
        fFunction(pNext, f);
        auto error = Dot(f, f);
        if (error < result.GetMinError())
        {
            result.SetMinErrorDifference(result.GetMinError() - error);
            result.SetMinUpdateLength(negJtf.Length());
            result.SetMinLocation(pNext);
            result.SetMinError(error);
            if (result.GetMinErrorDifference() <= errorDifferenceTolerance || result.GetMinUpdateLength() <= updateLengthTolerance)
            {
                result.SetConverged(true);
                return result;
            }
        }

        pCurrent = pNext;
    }

    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizer<Real>::ComputeLinearSystemInputs(const DVector& pCurrent)
{
    if (useJFunction)
    {
        jFunction(pCurrent, j);
        jtj = TransposeMultiply(j, j);
        negJtf = -(f * j);
    }
    else
    {
        jPlusFunction(pCurrent, jtj, negJtf);
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_DETAIL_H
