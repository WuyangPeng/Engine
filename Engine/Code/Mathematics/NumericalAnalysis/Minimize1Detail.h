///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H

#include "Minimize1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::Minimize1<Real, UserDataType>::Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData) noexcept
    : function{ function }, maxLevel{ maxLevel }, maxBracket{ maxBracket }, userData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::Minimize1<Real, UserDataType>::IsValid() const noexcept
{
    if (function != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::SetUserData(const UserDataType* newUserData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    userData = newUserData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::Minimize1<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return userData;
}

template <typename Real, typename UserDataType>
typename Mathematics::Minimize1<Real, UserDataType>::Minimize1Data Mathematics::Minimize1<Real, UserDataType>::GetMinimum(Real begin, Real end, Real initial) const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_1(begin <= initial && initial <= end, "无效的初始t值\n");

    Minimize1Data minimize1Data;

    const auto beginFunction = function(begin, userData);
    minimize1Data.CompareData(begin, beginFunction);

    const auto initialFunction = function(initial, userData);
    minimize1Data.CompareData(initial, initialFunction);

    const auto endFunction = function(end, userData);
    minimize1Data.CompareData(end, endFunction);

    CompareMinimum(begin, beginFunction, initial, initialFunction, end, endFunction, maxLevel, minimize1Data);

    return minimize1Data;
}

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>::CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
    if (level-- == 0)
    {
        return;
    }

    const auto middle = MathType::GetRational(1, 2) * (begin + end);
    const auto middleFunction = function(middle, userData);
    minimize1Data.CompareData(middle, middleFunction);

    if (MathType::GetValue(0) < beginFunction - (MathType::GetValue(2) * middleFunction + endFunction))
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
    for (auto i = 0; i < maxBracket; ++i)
    {
        // 更新最小值。
        minimize1Data.CompareData(middle, middleFunction);

        // 测试收敛。

        if (MathType::FAbs(end - begin) <= MathType::GetValue(2) * MathType::GetZeroTolerance() * MathType::FAbs(middle) + MathType::epsilon)
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
        if (MathType::FAbs(denom) < MathType::epsilon)
        {
            return;
        }

        auto vertex = MathType::GetRational(1, 2) * (endMinusMiddle * product1 - beginMinusMiddle * product0) / denom + middle;

        MATHEMATICS_ASSERTION_1(begin <= vertex && vertex <= end, "顶点不在区间\n");

        auto vertexFunction = function(vertex, userData);
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
