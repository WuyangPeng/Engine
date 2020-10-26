//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:29)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SQRT_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    // ��ģ�����sqrt(N)
    template <int N, int Low = 1, int High = N>
    class SqrtFirstAlgorithm
    {
    private:
        // �����е㣬ȡ��
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

    public:
        // ����һ�������ֵ�ڼ�����
        enum
        {
            Result = (N < Midpoint * Midpoint) ?
                         SqrtFirstAlgorithm<N, Low, Midpoint - 1>::Result :
                         SqrtFirstAlgorithm<N, Midpoint, High>::Result
        };
    };

    // �ֲ��ػ���Low ���� High
    template <int N, int Midpoint>
    class SqrtFirstAlgorithm<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    // ��ģ�����Ҫ�ݹ鲽��
    template <int N, int Low = 1, int High = N>
    class SqrtSecondAlgorithm
    {
    private:
        // �����е㣬ȡ��
        enum
        {
            Midpoint = (Low + High + 1) / 2
        };

        // ����һ�������ֵ�ڼ�����
        using SqrtSecondAlgorithmResult = typename IfThenElse<(N < Midpoint * Midpoint), SqrtSecondAlgorithm<N, Low, Midpoint - 1>, SqrtSecondAlgorithm<N, Midpoint, High>>::ResultType;

    public:
        enum
        {
            Result = SqrtSecondAlgorithmResult::Result
        };
    };

    // �ݹ������ƫ�ػ�
    template <int N, int Midpoint>
    class SqrtSecondAlgorithm<N, Midpoint, Midpoint>
    {
    public:
        enum
        {
            Result = Midpoint
        };
    };

    // ��ģ��,ͨ����������sqrt(N)
    template <int N, int I = 1>
    class SqrtThirdAlgorithm
    {
    public:
        enum
        {
            Result = (I * I < N) ? SqrtThirdAlgorithm<N, I + 1>::Result : I
        };
    };

    // �ݹ������ƫ�ػ�
    template <int N>
    class SqrtThirdAlgorithm<N, N>
    {
    public:
        enum
        {
            Result = N
        };
    };

    // ģ������ģ�������Ϊ���
    template <int N>
    class Value
    {
    public:
        enum
        {
            Result = N
        };
    };

    // ģ��ͨ����������sqrt(N)
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
