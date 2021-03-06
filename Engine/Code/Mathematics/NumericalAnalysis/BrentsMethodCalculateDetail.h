///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/23 18:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_DETAIL_H

#include "BrentsMethodCalculate.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::BrentsMethodCalculate<Real, UserDataType>::BrentsMethodCalculate(const BrentsMethod& brentsMethod, Real begin, Real end)
    : m_BrentsMethod{ brentsMethod },
      m_Begin{ begin },
      m_End{ end },
      m_BeginFunction{ m_BrentsMethod.GetFunctionValue(m_Begin) },
      m_EndFunction{ m_BrentsMethod.GetFunctionValue(m_End) },
      m_Bisect2Root{},
      m_SearchBegin{},
      m_SearchEnd{},
      m_SearchFunction{},
      m_PreviousBisected{ true },
      m_BeginEndFunctionDifference{},
      m_BeginSearchFunctionDifference{},
      m_EndSearchFunctionDifference{},
      m_Solution{},
      m_SolutionFunction{}
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
typename const Mathematics::BrentsMethodCalculate<Real, UserDataType>::BrentsMethodRoot Mathematics::BrentsMethodCalculate<Real, UserDataType>::GetRoot() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Bisect2Root;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::Calculate()
{
    if (IsBeginSatisfyConditions())
    {
        // 该端点是满足函数公差的近似根。
        m_Bisect2Root = BrentsMethodRoot{ m_Begin, m_BeginFunction, BrentsMethodRootType::HaveSolution };
    }
    else if (IsEndSatisfyConditions())
    {
        // 该端点是满足函数公差的近似根。
        m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction, BrentsMethodRootType::HaveSolution };
    }
    else if (m_BeginFunction * m_EndFunction < Math::GetValue(0))
    {
        Search();
    }
}

// private
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsBeginSatisfyConditions() const noexcept
{
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_BeginFunction && m_BeginFunction <= m_BrentsMethod.GetPositiveFTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// private
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsEndSatisfyConditions() const noexcept
{
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_EndFunction && m_EndFunction <= m_BrentsMethod.GetPositiveFTolerance())
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
    const auto maxIterations = m_BrentsMethod.GetMaxIterations();
    for (auto i = 0; i < maxIterations; ++i)
    {
        if (RootSearch())
        {
            return;
        }
    }

    m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction, BrentsMethodRootType::Unknown };
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::SwapBeginEnd() noexcept
{
    if (Math::FAbs(m_BeginFunction) < Math::FAbs(m_EndFunction))
    {
        // 交换m_Begin和m_End，使得|f(m_End)| <= |f(m_Begin)|。
        // 数值m_End被认为是根的最佳估计。
        std::swap(m_Begin, m_End);
        std::swap(m_BeginFunction, m_EndFunction);
    }
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InitSearchValue() noexcept
{
    m_SearchBegin = m_Begin;
    m_SearchEnd = m_Begin;
    m_SearchFunction = m_BeginFunction;
    m_PreviousBisected = true;
}

// private
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::RootSearch()
{
    UpdateFunctionDifference();

    if (Math::GetZeroTolerance() < Math::FAbs(m_BeginSearchFunctionDifference) &&
        Math::GetZeroTolerance() < Math::FAbs(m_EndSearchFunctionDifference))
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

    m_SolutionFunction = m_BrentsMethod.GetFunctionValue(m_Solution);

    // 评估函数在新的估计和收敛测试。
    if (IsSolutionSatisfyConditions())
    {
        m_Bisect2Root = BrentsMethodRoot{ m_Solution, m_SolutionFunction, BrentsMethodRootType::HaveSolution };
        return true;
    }

    // 更新的子间隔，以包括新的估计作为终点。
    UpdateSubinterval();

    // 允许该算法子间隔足够小时终止。
    if (IsConvXTolerance())
    {
        m_Bisect2Root = BrentsMethodRoot{ m_End, m_EndFunction, BrentsMethodRootType::HaveSolution };

        return true;
    }

    // 一个循环不变式是，x1是根估计，
    // f(m_Begin) * f(m_End) < 0，|f(m_End)| <= |f(m_Begin)|。
    SwapBeginEnd();

    return false;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::UpdateFunctionDifference() noexcept
{
    m_BeginEndFunctionDifference = m_BeginFunction - m_EndFunction;
    m_BeginSearchFunctionDifference = m_BeginFunction - m_SearchFunction;
    m_EndSearchFunctionDifference = m_EndFunction - m_SearchFunction;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InverseQuadratic() noexcept
{
    m_Solution = m_Begin * m_EndFunction * m_SearchFunction / m_BeginEndFunctionDifference / m_BeginSearchFunctionDifference -
                 m_End * m_BeginFunction * m_SearchFunction / m_BeginEndFunctionDifference / m_EndSearchFunctionDifference +
                 m_SearchBegin * m_BeginFunction * m_SearchFunction / m_BeginSearchFunctionDifference / m_EndSearchFunctionDifference;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::InverseLinear() noexcept
{
    m_Solution = (m_End * m_BeginFunction - m_Begin * m_EndFunction) / m_BeginEndFunctionDifference;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::AcceptOrRejectTests() noexcept
{
    auto solutionAvrDiff = m_Solution - Math::GetRational(3, 4) * m_Begin - Math::GetRational(1, 4) * m_End;

    auto solutionEndDiff = m_Solution - m_End;

    auto absSolutionEndDiff = Math::FAbs(solutionEndDiff);

    auto absEndSearchBeginDiff = Math::FAbs(m_End - m_SearchBegin);

    auto absSearchBeginSearchEndDiff = Math::FAbs(m_SearchBegin - m_SearchEnd);

    auto currentBisected = false;
    if (Math::GetZeroTolerance() < solutionAvrDiff * solutionEndDiff)
    {
        // 值s不是在0.75 * x0+0.25 * x1和x1之间。
        // 注：该算法有时有x0 < x1但有时x1 < x0，
        // 所以测试并没有使用简单的比较。
        currentBisected = true;
    }
    else if (m_PreviousBisected)
    {
        // Brent的第一测试，以确定是否接受该插值 。
        currentBisected = (Math::GetRational(1, 2) * absEndSearchBeginDiff) <= absSolutionEndDiff || (absEndSearchBeginDiff <= m_BrentsMethod.GetStepXTolerance());
    }
    else
    {
        // Brent的第二测试，以确定是否接受该插值 。
        currentBisected = ((Math::GetRational(1, 2) * absSearchBeginSearchEndDiff) <= absSolutionEndDiff || (absSearchBeginSearchEndDiff <= m_BrentsMethod.GetStepXTolerance()));
    }

    if (currentBisected)
    {
        // 其中一个额外的测试失败，
        // 所以拒绝插值，并用二分法来代替。
        m_Solution = Math::GetRational(1, 2) * (m_Begin + m_End);
        m_PreviousBisected = true;
    }
    else
    {
        m_PreviousBisected = false;
    }
}

// private
template <typename Real, typename UserDataType>
void Mathematics::BrentsMethodCalculate<Real, UserDataType>::UpdateSubinterval() noexcept
{
    m_SearchEnd = m_SearchBegin;
    m_SearchBegin = m_End;
    m_SearchFunction = m_EndFunction;
    if (m_BeginFunction * m_SolutionFunction < Math::GetValue(0))
    {
        m_End = m_Solution;
        m_EndFunction = m_SolutionFunction;
    }
    else
    {
        m_Begin = m_Solution;
        m_BeginFunction = m_SolutionFunction;
    }
}

// private
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsSolutionSatisfyConditions() const noexcept
{
    if (m_BrentsMethod.GetNegativeFTolerance() <= m_SolutionFunction && m_SolutionFunction <= m_BrentsMethod.GetPositiveFTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// private
template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethodCalculate<Real, UserDataType>::IsConvXTolerance() const noexcept
{
    if (Math::FAbs(m_End - m_Begin) <= m_BrentsMethod.GetConvXTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
