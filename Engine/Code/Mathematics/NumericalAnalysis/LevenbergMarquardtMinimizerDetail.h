/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 11:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_DETAIL_H

#include "LevenbergMarquardtMinimizer.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
Mathematics::LevenbergMarquardtMinimizer<T>::LevenbergMarquardtMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JFunction inJFunction)
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

template <typename T>
Mathematics::LevenbergMarquardtMinimizer<T>::LevenbergMarquardtMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JPlusFunction inJPlusFunction)
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

template <typename T>
bool Mathematics::LevenbergMarquardtMinimizer<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::LevenbergMarquardtMinimizer<T>::GetNumPDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numPDimensions;
}

template <typename T>
int Mathematics::LevenbergMarquardtMinimizer<T>::GetNumFDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numFDimensions;
}

template <typename T>
typename Mathematics::LevenbergMarquardtMinimizer<T>::LevenbergMarquardtMinimizerResultType Mathematics::LevenbergMarquardtMinimizer<T>::operator()(const DVector& p0, int maxIterations, T updateLengthTolerance, T errorDifferenceTolerance, T lambdaFactor, T lambdaAdjust, int maxAdjustments)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    LevenbergMarquardtMinimizerResultType result{};
    result.SetMinLocation(p0);
    result.SetMinError(std::numeric_limits<T>::max());
    result.SetMinErrorDifference(std::numeric_limits<T>::max());
    result.SetMinUpdateLength(T{});
    result.SetNumIterations(0);
    result.SetNumAdjustments(0);
    result.SetConverged(false);

    /// 作为一个简单的预防措施，请确保lambda输入是有效的。
    /// 如果无效，则返回到高斯-牛顿迭代。
    if (lambdaFactor <= T{} || lambdaAdjust <= T{})
    {
        maxAdjustments = 1;
        lambdaFactor = T{};
        lambdaAdjust = Math::GetValue(1);
    }

    /// 作为一个简单的预防措施，确保公差为非负。
    updateLengthTolerance = std::max(updateLengthTolerance, T{});
    errorDifferenceTolerance = std::max(errorDifferenceTolerance, T{});

    /// 计算初始误差。
    fFunction(p0, f);
    result.SetMinError(Dot(f, f));

    /// 进行Levenberg-Marquart迭代。
    auto pCurrent = p0;
    for (result.SetNumIterations(1); result.GetNumIterations() <= maxIterations; result.AddNumIterations())
    {
        std::pair<bool, bool> status;
        DVector pNext{};
        for (result.SetNumAdjustments(0); result.GetNumAdjustments() < maxAdjustments; result.AddNumAdjustments())
        {
            status = DoIteration(pCurrent, lambdaFactor, updateLengthTolerance, errorDifferenceTolerance, pNext, result);
            if (status.first)
            {
                /// Cholesky分解失败，或者迭代收敛在容差范围内。
                /// 请参阅DoIteration中关于Cholesky分解未失败的注释。
                return result;
            }

            if (status.second)
            {
                /// 误差已经减少，但我们还没有收敛到允许的范围内。
                break;
            }

            lambdaFactor *= lambdaAdjust;
        }

        if (result.GetNumAdjustments() < maxAdjustments)
        {
            /// lambda的当前值使我们进行了更新，减少了错误，但错误还不小，无法得出收敛的结论。
            /// 为下一次外循环迭代减少lambda。
            lambdaFactor /= lambdaAdjust;
        }
        else
        {
            /// 在内部循环迭代过程中尝试的所有lambda都没有减少错误。
            /// 如果我们在这里什么都不做，下一次内部循环迭代将继续与lambda相乘，有可能导致最终的浮点溢出。
            /// 为了避免这种情况，回到高斯-牛顿迭代。
            status = DoIteration(pCurrent, lambdaFactor, updateLengthTolerance, errorDifferenceTolerance, pNext, result);
            if (status.first)
            {
                /// Cholesky分解失败，或者迭代收敛在容差范围内。
                /// 请参阅DoIteration中关于Cholesky分解未失败的注释。
                return result;
            }
        }

        pCurrent = pNext;
    }

    return result;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizer<T>::ComputeLinearSystemInputs(const DVector& pCurrent, T lambda)
{
    if (useJFunction)
    {
        jFunction(pCurrent, j);
        jtj = MultiplyTranspose(j, j);
        negJtf = -(f * j);
    }
    else
    {
        jPlusFunction(pCurrent, jtj, negJtf);
    }

    T diagonalSum{};
    for (auto i = 0; i < numPDimensions; ++i)
    {
        diagonalSum += jtj(i, i);
    }

    auto diagonalAdjust = lambda * diagonalSum / boost::numeric_cast<T>(numPDimensions);
    for (auto i = 0; i < numPDimensions; ++i)
    {
        jtj(i, i) += diagonalAdjust;
    }
}

template <typename T>
std::pair<bool, bool> Mathematics::LevenbergMarquardtMinimizer<T>::DoIteration(DVector const& pCurrent, T lambdaFactor, T updateLengthTolerance, T errorDifferenceTolerance, DVector& pNext, LevenbergMarquardtMinimizerResultType& result)
{
    ComputeLinearSystemInputs(pCurrent, lambdaFactor);
    if (!decomposer.Factor(jtj))
    {
        /// 矩阵jtj是正半定的，所以当jtj具有零特征值时，
        /// 可能会发生故障，在这种情况下jtj不可逆。
        /// 无论如何都要生成迭代，也许使用梯度下降？
        return std::make_pair(true, false);
    }
    negJtf = decomposer.SolveLower(jtj);
    negJtf = decomposer.SolveUpper(jtj);

    pNext = pCurrent + negJtf;
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
            return std::make_pair(true, true);
        }
        else
        {
            return std::make_pair(false, true);
        }
    }
    else
    {
        return std::make_pair(false, false);
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_DETAIL_H
