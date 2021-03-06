///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 13:41)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H

#include "Minimize1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::Minimize1<Real, UserDataType>::Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData) noexcept
    : m_Function{ function }, m_MaxLevel{ maxLevel }, m_MaxBracket{ maxBracket }, m_UserData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::Minimize1<Real, UserDataType>::IsValid() const noexcept
{
    if (m_Function != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::SetUserData(const UserDataType* userData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_UserData = userData;
}

template <typename Real, typename UserDataType>
typename const UserDataType* Mathematics::Minimize1<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UserData;
}

template <typename Real, typename UserDataType>
typename const Mathematics::Minimize1<Real, UserDataType>::Minimize1Data Mathematics::Minimize1<Real, UserDataType>::GetMinimum(Real begin, Real end, Real initial) const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_1(begin <= initial && initial <= end, "无效的初始t值\n");

    Minimize1Data minimize1Data;

    auto beginFunction = m_Function(begin, m_UserData);
    minimize1Data.CompareData(begin, beginFunction);

    auto initialFunction = m_Function(initial, m_UserData);
    minimize1Data.CompareData(initial, initialFunction);

    auto endFunction = m_Function(end, m_UserData);
    minimize1Data.CompareData(end, endFunction);

    CompareMinimum(begin, beginFunction, initial, initialFunction, end, endFunction, m_MaxLevel, minimize1Data);

    return minimize1Data;
}

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
    if (level-- == 0)
    {
        return;
    }

    auto middle = Math::GetRational(1, 2) * (begin + end);
    auto middleFunction = m_Function(middle, m_UserData);
    minimize1Data.CompareData(middle, middleFunction);

    if (Math::GetValue(0) < beginFunction - (Math::GetValue(2) * middleFunction + endFunction))
    {
        // 二次拟合具有中点正二阶导数。
        if (beginFunction < endFunction)
        {
            if (beginFunction <= middleFunction)
            {
                // 增加，重复在 [begin,middle]。
                CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            }
            else
            {
                // 不单调，有一个括号
                CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
            }
        }
        else if (endFunction < beginFunction)
        {
            if (endFunction <= middleFunction)
            {
                // 减少, 重复在 [middle,end].
                CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
            }
            else
            {
                // 不单调，有一个括号
                CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
            }
        }
        else
        {
            // 常数，重复在[begin,middle] 和  [middle,end]。
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
    }
    else
    {
        // 二次拟合具有中点非正数二阶导数。

        if (beginFunction < endFunction)
        {
            // 重复在  [begin,middle]。
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
        }
        else if (endFunction < beginFunction)
        {
            // 重复在 [middle,end]。
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
        else
        {
            // 重复在[begin,middle] 和  [middle,end]。
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
    }
}

// private
template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::CompareMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
    if (level-- == 0)
    {
        return;
    }

    if ((middle - begin) * (middleFunction - endFunction) < (end - middle) * (beginFunction - middleFunction))
    {
        // 二次拟合具有中点正二阶导数。
        if (beginFunction < endFunction)
        {
            if (beginFunction <= middleFunction)
            {
                // 增加，重复在[begin,middle]。
                CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            }
            else
            {
                // 不单调，有一个括号
                CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
            }
        }
        else if (endFunction < beginFunction)
        {
            if (endFunction <= middleFunction)
            {
                // 减少, 重复在[middle,end].
                CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
            }
            else
            {
                // 不单调，有一个括号
                CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
            }
        }
        else
        {
            // 常数，重复在[begin,middle] 和 [middle,end]。
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
    }
    else
    {
        // 二次拟合具有中点非正数二阶导数。
        if (beginFunction < endFunction)
        {
            // 重复在[begin,middle] .
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
        }
        else if (endFunction < beginFunction)
        {
            // 重复在 [middle,end].
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
        else
        {
            // 重复在 [begin,middle]  和[middle,end]
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
    }
}

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::CompareBracketedMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
    for (auto i = 0; i < m_MaxBracket; ++i)
    {
        // 更新最小值。
        minimize1Data.CompareData(middle, middleFunction);

        // 测试收敛。

        if (Math::FAbs(end - begin) <= Math::GetValue(2) * Math::GetZeroTolerance() * Math::FAbs(middle) + Math::sm_Epsilon)
        {
            break;
        }

        // 插值计算抛物线的顶点。
        auto beginMinusMiddle = begin - middle;
        auto endMinusMiddle = end - middle;
        auto beginFunctionMinusMiddleFunction = beginFunction - middleFunction;
        auto endFunctionMinusMiddleFunction = endFunction - middleFunction;
        auto product0 = beginMinusMiddle * endFunctionMinusMiddleFunction;
        auto product1 = endMinusMiddle * beginFunctionMinusMiddleFunction;
        auto denom = product1 - product0;
        if (Math::FAbs(denom) < Math::sm_Epsilon)
        {
            return;
        }

        auto vertex = Math::GetRational(1, 2) * (endMinusMiddle * product1 - beginMinusMiddle * product0) / denom + middle;

        MATHEMATICS_ASSERTION_1(begin <= vertex && vertex <= end, "顶点不在区间\n");

        auto vertexFunction = m_Function(vertex, m_UserData);
        minimize1Data.CompareData(vertex, vertexFunction);

        if (vertex < middle)
        {
            if (vertexFunction < middleFunction)
            {
                end = middle;
                endFunction = middleFunction;
                middle = vertex;
                middleFunction = vertexFunction;
            }
            else
            {
                begin = vertex;
                beginFunction = vertexFunction;
            }
        }
        else if (middle < vertex)
        {
            if (vertexFunction < middleFunction)
            {
                begin = middle;
                beginFunction = middleFunction;
                middle = vertex;
                middleFunction = vertexFunction;
            }
            else
            {
                end = vertex;
                endFunction = vertexFunction;
            }
        }
        else
        {
            // 抛物线的顶点为中间的采样点。
            CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
            CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H
