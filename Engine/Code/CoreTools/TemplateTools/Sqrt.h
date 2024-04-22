/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:11)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    /// 主模板计算sqrt(N)
    template <int N, int Low = 1, int High = N>
    class SqrtAlgorithm0
    {
    private:
        /// 计算中点，取整
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

    public:
        /// 搜索一个不大的值在减半间隔
        enum
        {
            Result = (N < Midpoint * Midpoint) ? (SqrtAlgorithm0<N, Low, Midpoint - 1>::Result) : (SqrtAlgorithm0<N, Midpoint, High>::Result)
        };
    };

    /// 局部特化当Low 等于 High
    template <int N, int Midpoint>
    class SqrtAlgorithm0<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    /// 主模板对主要递归步骤
    template <int N, int Low = 1, int High = N>
    class SqrtAlgorithm1
    {
    private:
        /// 计算中点，取整
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

        /// 搜索一个不大的值在减半间隔
        using SqrtAlgorithm1Result = typename IfThenElse<(N < Midpoint * Midpoint), SqrtAlgorithm1<N, Low, Midpoint - 1>, SqrtAlgorithm1<N, Midpoint, High>>::ResultType;

    public:
        enum
        {
            Result = SqrtAlgorithm1Result::Result
        };
    };

    /// 递归结束的偏特化
    template <int N, int Midpoint>
    class SqrtAlgorithm1<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    /// 主模板,通过迭代计算sqrt(N)
    template <int N, int I = 1>
    class SqrtAlgorithm2
    {
    public:
        enum
        {
            Result = (I * I < N) ? (SqrtAlgorithm2<N, I + 1>::Result) : I
        };
    };

    // 递归结束的偏特化
    template <int N>
    class SqrtAlgorithm2<N, N>
    {
    public:
        enum
        {
            Result = N
        };
    };

    /// 模板生成模板参数作为结果
    template <int N>
    class Value
    {
    public:
        enum
        {
            Result = N
        };
    };

    /// 模板通过迭代计算sqrt(N)
    template <int N, int I = 1>
    class SqrtAlgorithm3
    {
    public:
        using SqrtAlgorithmResult = typename IfThenElse<(I * I < N), SqrtAlgorithm3<N, I + 1>, Value<I>>::ResultType;

        enum
        {
            Result = SqrtAlgorithmResult::Result
        };
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
