/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:11)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    /// ��ģ�����sqrt(N)
    template <int N, int Low = 1, int High = N>
    class SqrtAlgorithm0
    {
    private:
        /// �����е㣬ȡ��
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

    public:
        /// ����һ�������ֵ�ڼ�����
        enum
        {
            Result = (N < Midpoint * Midpoint) ? (SqrtAlgorithm0<N, Low, Midpoint - 1>::Result) : (SqrtAlgorithm0<N, Midpoint, High>::Result)
        };
    };

    /// �ֲ��ػ���Low ���� High
    template <int N, int Midpoint>
    class SqrtAlgorithm0<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    /// ��ģ�����Ҫ�ݹ鲽��
    template <int N, int Low = 1, int High = N>
    class SqrtAlgorithm1
    {
    private:
        /// �����е㣬ȡ��
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

        /// ����һ�������ֵ�ڼ�����
        using SqrtAlgorithm1Result = typename IfThenElse<(N < Midpoint * Midpoint), SqrtAlgorithm1<N, Low, Midpoint - 1>, SqrtAlgorithm1<N, Midpoint, High>>::ResultType;

    public:
        enum
        {
            Result = SqrtAlgorithm1Result::Result
        };
    };

    /// �ݹ������ƫ�ػ�
    template <int N, int Midpoint>
    class SqrtAlgorithm1<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    /// ��ģ��,ͨ����������sqrt(N)
    template <int N, int I = 1>
    class SqrtAlgorithm2
    {
    public:
        enum
        {
            Result = (I * I < N) ? (SqrtAlgorithm2<N, I + 1>::Result) : I
        };
    };

    // �ݹ������ƫ�ػ�
    template <int N>
    class SqrtAlgorithm2<N, N>
    {
    public:
        enum
        {
            Result = N
        };
    };

    /// ģ������ģ�������Ϊ���
    template <int N>
    class Value
    {
    public:
        enum
        {
            Result = N
        };
    };

    /// ģ��ͨ����������sqrt(N)
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
