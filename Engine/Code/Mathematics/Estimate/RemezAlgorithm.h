///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/09 16:04)

#ifndef MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_H
#define MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    template <typename T>
    class RemezAlgorithm
    {
    public:
        using ClassType = RemezAlgorithm<T>;

        using Function = std::function<T(const T&)>;
        using Container = std::vector<T>;

    public:
        RemezAlgorithm() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int Execute(const Function& function,
                              const Function& functionDer,
                              const T& xMin,
                              const T& xMax,
                              int degree,
                              int maxRemezIterations,
                              int maxBisectionIterations,
                              int maxBracketIterations);

        // 算法的输出。
        NODISCARD Container GetCoefficients() const;

        NODISCARD T GetEstimatedMaxError() const;
        NODISCARD Container GetXNodes() const;
        NODISCARD Container GetErrors() const;

    private:
        void ComputeInitialXNodes();

        void ComputeFAtXNodes();

        // 计算多项式u(x)，其中u(x[i]) = F(x[i])。
        void ComputeUCoefficients();

        // 计算多项式v(x)，其中 v(x[i]) = (-1)^i。
        void ComputeVCoefficients();

        void ComputeEstimatedError();

        void ComputePCoefficients();

        NODISCARD bool IsOscillatory();

        void ComputePartition();

        // 使用二次拟合线搜索（QFLS）来找到局部极值。
        void ComputeXExtremes();

        NODISCARD T GetXExtreme(T x0, T x1);

        // 评估 u(x) =
        //   u[0]+(x-xn[0])*(u[1]+(x-xn[1])*(u[2]+...+(x-xn[n-1])*u[n-1]))
        NODISCARD T EvaluateU(const T& x);

        // 评估 v(x) =
        //   v[0]+(x-xn[0])*(v[1]+(x-xn[1])*(v[2]+...+(x-xn[n-1])*v[n-1]))
        NODISCARD T EvaluateV(const T& x);

        // 评估 p(x) = sum_{i=0}^{n} p[i] * x^i.
        NODISCARD T EvaluateP(const T& x);

        NODISCARD T EvaluatePDer(const T& x);

    private:
        // 要执行的输入(...)。
        Function inputFunction;
        Function inputFunctionDer;
        T inputXMin;
        T inputXMax;
        int inputDegree;
        int inputMaxRemezIterations;
        int inputMaxBisectionIterations;
        int inputMaxBracketIterations;

        // 执行的输出(...)。
        Container coefficients;
        T estimatedMaxError;
        Container xNodes;
        Container errors;

        // 中间计算中使用的成员。
        Container fValues;
        Container uCoefficients;
        Container vCoefficients;
        Container partition;
    };

}

#endif  // MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_H
