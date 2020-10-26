//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:29)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    // 主模板计算sqrt(N)
    template <int N, int Low = 1, int High = N>
    class SqrtFirstAlgorithm
    {
    private:
        // 计算中点，取整
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

    public:
        // 搜索一个不大的值在减半间隔
        enum
        {
            Result = (N < Midpoint * Midpoint) ?
                         SqrtFirstAlgorithm<N, Low, Midpoint - 1>::Result :
                         SqrtFirstAlgorithm<N, Midpoint, High>::Result
        };
    };

    // 局部特化当Low 等于 High
    template <int N, int Midpoint>
    class SqrtFirstAlgorithm<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    // 主模板对主要递归步骤
    template <int N, int Low = 1, int High = N>
    class SqrtSecondAlgorithm
    {
    private:
        // 计算中点，取整
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

        // 搜索一个不大的值在减半间隔
        using SqrtSecondAlgorithmResult = typename IfThenElse<(N < Midpoint * Midpoint), SqrtSecondAlgorithm<N, Low, Midpoint - 1>, SqrtSecondAlgorithm<N, Midpoint, High>>::ResultType;

    public:
        enum
        {
            Result = SqrtSecondAlgorithmResult::Result
        };
    };

    // 递归结束的偏特化
    template <int N, int Midpoint>
    class SqrtSecondAlgorithm<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    // 主模板,通过迭代计算sqrt(N)
    template <int N, int I = 1>
    class SqrtThirdAlgorithm
    {
    public:
        enum
        {
            Result = (I * I < N) ? SqrtThirdAlgorithm<N, I + 1>::Result : I
        };
    };

    // 递归结束的偏特化
    template <int N>
    class SqrtThirdAlgorithm<N, N>
    {
    public:
        enum
        {
            Result = N
        };
    };

    // 模板生成模板参数作为结果
    template <int N>
    class Value
    {
    public:
        enum
        {
            Result = N
        };
    };

    // 模板通过迭代计算sqrt(N)
    template <int N, int I = 1>
    class SqrtFourthAlgorithm
    {
    public:
        using SqrtFourthAlgorithmResult = typename IfThenElse<(I * I < N), SqrtFourthAlgorithm<N, I + 1>, Value<I>>::ResultType;
        enum
        {
            Result = SqrtFourthAlgorithmResult::Result
        };
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
