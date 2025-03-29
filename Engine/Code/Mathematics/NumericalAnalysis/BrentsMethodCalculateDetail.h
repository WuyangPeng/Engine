///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H

#include "BrentsMethod.h"
#include "BrentsMethodCalculate.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::BrentsMethodCalculate<Real, UserDataType>::BrentsMethodCalculate(const BrentsMethodType& brentsMethod, Real begin, Real end)
    : brentsMethod{ brentsMethod },
      begin{ begin },
      end{ end },
      beginFunction{ brentsMethod.GetFunctionValue(begin) },
      endFunction{ brentsMethod.GetFunctionValue(end) },
      bisect2Root{},
      searchBegin{},
      searchEnd{},
      searchFunction{},
      previousBisected{ true },
      beginEndFunctionDifference{},
      beginSearchFunctionDifference{},
      endSearchFunctionDifference{},
      solution{},
      solutionFunction{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::BrentsMethodCalculate<Real, UserDataType>::BrentsMethodRootType Mathematics::BrentsMethodCalculate<Real, UserDataType>::GetRoot() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bisect2Root;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::Calculate()
{
    if (IsBeginSatisfyConditions())
    {
        // 该端点是满足函数公差的近似根。
        bisect2Root = BrentsMethodRootType{ begin, beginFunction, BrentsMethodRootType::HaveSolution };
    }
    else if (IsEndSatisfyConditions())
    {
        // 该端点是满足函数公差的近似根。
        bisect2Root = BrentsMethodRootType{ end, endFunction, BrentsMethodRootType::HaveSolution };
    }
    else if (beginFunction * endFunction < MathType::GetValue(0))
    {
        Search();
    }
}

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsBeginSatisfyConditions() const noexcept
{
    if (brentsMethod.GetNegativeFTolerance() <= beginFunction && beginFunction <= brentsMethod.GetPositiveFTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsEndSatisfyConditions() const noexcept
{
    if (brentsMethod.GetNegativeFTolerance() <= endFunction && endFunction <= brentsMethod.GetPositiveFTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::Search()
{
    SwapBeginEnd();

    // 初始化根搜索的值。
    InitSearchValue();

    // 根搜索
    const auto maxIterations = brentsMethod.GetMaxIterations();
    for (auto i = 0; i < maxIterations; ++i)
    {
        if (RootSearch())
        {
            return;
        }
    }

    bisect2Root = BrentsMethodRootType{ end, endFunction, BrentsMethodRootType::Unknown };
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::SwapBeginEnd() noexcept
{
    if (MathType::FAbs(beginFunction) < MathType::FAbs(endFunction))
    {
        // 交换m_Begin和m_End，使得|f(end)| <= |f(begin)|。
        // 数值m_End被认为是根的最佳估计。
        std::swap(begin, end);
        std::swap(beginFunction, endFunction);
    }
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InitSearchValue() noexcept
{
    searchBegin = begin;
    searchEnd = begin;
    searchFunction = beginFunction;
    previousBisected = true;
}

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::RootSearch()
{
    UpdateFunctionDifference();

    if (MathType::GetZeroTolerance() < MathType::FAbs(beginSearchFunctionDifference) &&
        MathType::GetZeroTolerance() < MathType::FAbs(endSearchFunctionDifference))
    {
        // 使用逆二次插值。
        InverseQuadratic();
    }
    else
    {
        // 使用逆线性插值（割线法）。
        InverseLinear();
    }

    // 计算值需要进行接受或拒绝测试。
    AcceptOrRejectTests();

    solutionFunction = brentsMethod.GetFunctionValue(solution);

    // 评估函数在新的估计和收敛测试。
    if (IsSolutionSatisfyConditions())
    {
        bisect2Root = BrentsMethodRootType{ solution, solutionFunction, BrentsMethodRootType::HaveSolution };
        return true;
    }

    // 更新的子间隔，以包括新的估计作为终点。
    UpdateSubinterval();

    // 允许该算法子间隔足够小时终止。
    if (IsConvXTolerance())
    {
        bisect2Root = BrentsMethodRootType{ end, endFunction, BrentsMethodRootType::HaveSolution };

        return true;
    }

    // 一个循环不变式是，x1是根估计，
    // f(begin) * f(end) < 0，|f(end)| <= |f(begin)|。
    SwapBeginEnd();

    return false;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::UpdateFunctionDifference() noexcept
{
    beginEndFunctionDifference = beginFunction - endFunction;
    beginSearchFunctionDifference = beginFunction - searchFunction;
    endSearchFunctionDifference = endFunction - searchFunction;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InverseQuadratic() noexcept
{
    solution = begin * endFunction * searchFunction / beginEndFunctionDifference / beginSearchFunctionDifference -
               end * beginFunction * searchFunction / beginEndFunctionDifference / endSearchFunctionDifference +
               searchBegin * beginFunction * searchFunction / beginSearchFunctionDifference / endSearchFunctionDifference;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InverseLinear() noexcept
{
    solution = (end * beginFunction - begin * endFunction) / beginEndFunctionDifference;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::AcceptOrRejectTests() noexcept
{
    auto solutionAvrDiff = solution - MathType::GetRational(3, 4) * begin - MathType::GetRational(1, 4) * end;

    auto solutionEndDiff = solution - end;

    auto absSolutionEndDiff = MathType::FAbs(solutionEndDiff);

    auto absEndSearchBeginDiff = MathType::FAbs(end - searchBegin);

    auto absSearchBeginSearchEndDiff = MathType::FAbs(searchBegin - searchEnd);

    auto currentBisected = false;
    if (MathType::GetZeroTolerance() < solutionAvrDiff * solutionEndDiff)
    {
        // 值s不是在0.75 * x0+0.25 * x1和x1之间。
        // 注：该算法有时有x0 < x1但有时x1 < x0，
        // 所以测试并没有使用简单的比较。
        currentBisected = true;
    }
    else if (previousBisected)
    {
        // Brent的第一测试，以确定是否接受该插值 。
        currentBisected = (MathType::GetRational(1, 2) * absEndSearchBeginDiff) <= absSolutionEndDiff || (absEndSearchBeginDiff <= brentsMethod.GetStepXTolerance());
    }
    else
    {
        // Brent的第二测试，以确定是否接受该插值 。
        currentBisected = ((MathType::GetRational(1, 2) * absSearchBeginSearchEndDiff) <= absSolutionEndDiff || (absSearchBeginSearchEndDiff <= brentsMethod.GetStepXTolerance()));
    }

    if (currentBisected)
    {
        // 其中一个额外的测试失败，
        // 所以拒绝插值，并用二分法来代替。
        solution = MathType::GetRational(1, 2) * (begin + end);
        previousBisected = true;
    }
    else
    {
        previousBisected = false;
    }
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::UpdateSubinterval() noexcept
{
    searchEnd = searchBegin;
    searchBegin = end;
    searchFunction = endFunction;
    if (beginFunction * solutionFunction < MathType::GetValue(0))
    {
        end = solution;
        endFunction = solutionFunction;
    }
    else
    {
        begin = solution;
        beginFunction = solutionFunction;
    }
}

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsSolutionSatisfyConditions() const noexcept
{
    if (brentsMethod.GetNegativeFTolerance() <= solutionFunction && solutionFunction <= brentsMethod.GetPositiveFTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsConvXTolerance() const noexcept
{
    if (MathType::FAbs(end - begin) <= brentsMethod.GetConvXTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
