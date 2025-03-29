///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:50)

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
        // �ö˵������㺯������Ľ��Ƹ���
        bisect2Root = BrentsMethodRootType{ begin, beginFunction, BrentsMethodRootType::HaveSolution };
    }
    else if (IsEndSatisfyConditions())
    {
        // �ö˵������㺯������Ľ��Ƹ���
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

    // ��ʼ����������ֵ��
    InitSearchValue();

    // ������
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
        // ����m_Begin��m_End��ʹ��|f(end)| <= |f(begin)|��
        // ��ֵm_End����Ϊ�Ǹ�����ѹ��ơ�
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
        // ʹ������β�ֵ��
        InverseQuadratic();
    }
    else
    {
        // ʹ�������Բ�ֵ�����߷�����
        InverseLinear();
    }

    // ����ֵ��Ҫ���н��ܻ�ܾ����ԡ�
    AcceptOrRejectTests();

    solutionFunction = brentsMethod.GetFunctionValue(solution);

    // �����������µĹ��ƺ��������ԡ�
    if (IsSolutionSatisfyConditions())
    {
        bisect2Root = BrentsMethodRootType{ solution, solutionFunction, BrentsMethodRootType::HaveSolution };
        return true;
    }

    // ���µ��Ӽ�����԰����µĹ�����Ϊ�յ㡣
    UpdateSubinterval();

    // ������㷨�Ӽ���㹻Сʱ��ֹ��
    if (IsConvXTolerance())
    {
        bisect2Root = BrentsMethodRootType{ end, endFunction, BrentsMethodRootType::HaveSolution };

        return true;
    }

    // һ��ѭ������ʽ�ǣ�x1�Ǹ����ƣ�
    // f(begin) * f(end) < 0��|f(end)| <= |f(begin)|��
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
        // ֵs������0.75 * x0+0.25 * x1��x1֮�䡣
        // ע�����㷨��ʱ��x0 < x1����ʱx1 < x0��
        // ���Բ��Բ�û��ʹ�ü򵥵ıȽϡ�
        currentBisected = true;
    }
    else if (previousBisected)
    {
        // Brent�ĵ�һ���ԣ���ȷ���Ƿ���ܸò�ֵ ��
        currentBisected = (MathType::GetRational(1, 2) * absEndSearchBeginDiff) <= absSolutionEndDiff || (absEndSearchBeginDiff <= brentsMethod.GetStepXTolerance());
    }
    else
    {
        // Brent�ĵڶ����ԣ���ȷ���Ƿ���ܸò�ֵ ��
        currentBisected = ((MathType::GetRational(1, 2) * absSearchBeginSearchEndDiff) <= absSolutionEndDiff || (absSearchBeginSearchEndDiff <= brentsMethod.GetStepXTolerance()));
    }

    if (currentBisected)
    {
        // ����һ������Ĳ���ʧ�ܣ�
        // ���Ծܾ���ֵ�����ö��ַ������档
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
