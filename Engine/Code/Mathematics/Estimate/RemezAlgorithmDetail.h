///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/09 16:04)

#ifndef MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_DETAIL_H
#define MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_DETAIL_H

#include "RemezAlgorithm.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T>
Mathematics::RemezAlgorithm<T>::RemezAlgorithm() noexcept
    : inputFunction{},
      inputFunctionDer{},
      inputXMin{ 0 },
      inputXMax{ 0 },
      inputDegree{ 0 },
      inputMaxRemezIterations{ 0 },
      inputMaxBisectionIterations{ 0 },
      inputMaxBracketIterations{ 0 },
      coefficients{},
      estimatedMaxError{ 0 },
      xNodes{},
      errors{},
      fValues{},
      uCoefficients{},
      vCoefficients{},
      partition{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
int Mathematics::RemezAlgorithm<T>::Execute(const Function& function, const Function& functionDer, const T& xMin, const T& xMax, int degree, int maxRemezIterations, int maxBisectionIterations, int maxBracketIterations)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!(xMin < xMax &&
          degree > 0 &&
          maxRemezIterations > 0 &&
          maxBisectionIterations > 0 &&
          maxBracketIterations > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入"))
    }

    inputFunction = function;
    inputFunctionDer = functionDer;
    inputXMin = xMin;
    inputXMax = xMax;
    inputDegree = degree;
    inputMaxRemezIterations = maxRemezIterations;
    inputMaxBisectionIterations = maxBisectionIterations;
    inputMaxBracketIterations = maxBracketIterations;

    coefficients.resize(inputDegree + 1);
    estimatedMaxError = Math<T>::GetValue(0);
    xNodes.resize(inputDegree + 2);
    errors.resize(inputDegree + 2);

    fValues.resize(inputDegree + 2);
    uCoefficients.resize(inputDegree + 1);
    vCoefficients.resize(inputDegree + 1);
    estimatedMaxError = Math<T>::GetValue(0);
    partition.resize(inputDegree + 3);

    ComputeInitialXNodes();
    auto iteration = 0;
    for (iteration = 0; iteration < inputMaxRemezIterations; ++iteration)
    {
        ComputeFAtXNodes();
        ComputeUCoefficients();
        ComputeVCoefficients();
        ComputeEstimatedError();
        ComputePCoefficients();
        if (IsOscillatory())
        {
            ComputePartition();
            ComputeXExtremes();
        }
        else
        {
            iteration = std::numeric_limits<size_t>::max();
            break;
        }
    }

    return iteration;
}

template <typename T>
typename Mathematics::RemezAlgorithm<T>::Container Mathematics::RemezAlgorithm<T>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return coefficients;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::GetEstimatedMaxError() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return estimatedMaxError;
}

template <typename T>
typename Mathematics::RemezAlgorithm<T>::Container Mathematics::RemezAlgorithm<T>::GetXNodes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xNodes;
}

template <typename T>
typename Mathematics::RemezAlgorithm<T>::Container Mathematics::RemezAlgorithm<T>::GetErrors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return errors;
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeInitialXNodes()
{
    // 获取区间 [-1,1]的Chebyshev节点。
    const auto numNodes = xNodes.size();
    const auto halfPiDivDegree = Math<T>::GetHalfPI() / static_cast<T>(inputDegree);
    Container cosAngles(numNodes);
    cosAngles.front() = Math<T>::GetValue(-1);
    for (auto i = 1, j = 2 * inputDegree - 1; i <= inputDegree; ++i, j -= 2)
    {
        auto angle = static_cast<T>(j) * halfPiDivDegree;
        cosAngles[i] = std::cos(angle);
    }
    cosAngles.back() = Math<T>::GetValue(1);
    if (numNodes & 1)
    {
        // 当角度为pi/2时，避免舍入误差，其中cos(pi/2)理论上为零。
        cosAngles[numNodes / 2] = Math<T>::GetValue(0);
    }

    // 将节点转换为间隔[xMin, xMax]。
    const auto center = Math<T>::GetRational(1, 2) * (inputXMax + inputXMin);
    const auto radius = Math<T>::GetRational(1, 2) * (inputXMax - inputXMin);
    xNodes.front() = inputXMin;
    for (auto i = 1; i <= inputDegree; ++i)
    {
        xNodes[i] = center + radius * cosAngles[i];
    }
    xNodes.back() = inputXMax;
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeFAtXNodes()
{
    for (auto i = 0u; i < xNodes.size(); ++i)
    {
        fValues[i] = inputFunction(xNodes[i]);
    }
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeUCoefficients()
{
    for (auto i = 0u; i < uCoefficients.size(); ++i)
    {
        uCoefficients[i] = fValues[i];
        for (auto j = 0u; j < i; ++j)
        {
            uCoefficients[i] -= uCoefficients[j];
            uCoefficients[i] /= xNodes[i] - xNodes[j];
        }
    }
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeVCoefficients()
{
    auto sign = Math<T>::GetValue(1);
    for (auto i = 0; i < vCoefficients.size(); ++i)
    {
        vCoefficients[i] = sign;
        for (auto j = 0; j < i; ++j)
        {
            vCoefficients[i] -= vCoefficients[j];
            vCoefficients[i] /= xNodes[i] - xNodes[j];
        }
        sign = -sign;
    }
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeEstimatedError()
{
    const auto powNegOne = ((inputDegree & 1) ? Math<T>::GetValue(-1) : Math<T>::GetValue(1));
    const auto& xBack = xNodes.back();
    const auto& fBack = fValues.back();
    auto uBack = EvaluateU(xBack);
    auto vBack = EvaluateV(xBack);
    estimatedMaxError = (uBack - fBack) / (vBack + powNegOne);
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputePCoefficients()
{
    // 将P多项式符号化地计算为牛顿多项式，以便从t次幂中获得系数。
    Container constant(uCoefficients.size());
    for (auto i = 0; i < uCoefficients.size(); ++i)
    {
        constant[i] = uCoefficients[i] - estimatedMaxError * vCoefficients[i];
    }

    auto index = uCoefficients.size() - 1;
    Polynomial<T> poly{ constant[index--] };
    for (auto i = 1; i < uCoefficients.size(); ++i, --index)
    {
        Polynomial<T> linear{ -xNodes[index], Math<T>::GetValue(1) };
        poly = constant[index] + linear * poly;
    }

    for (auto i = 0; i < coefficients.size(); ++i)
    {
        coefficients[i] = poly[i];
    }
}

template <typename T>
bool Mathematics::RemezAlgorithm<T>::IsOscillatory()
{
    // 计算当前节点的误差|F(x)-P(x)|，并验证它们是振荡的。
    for (auto i = 0; i < xNodes.size(); ++i)
    {
        errors[i] = inputFunction(xNodes[i]) - EvaluateP(xNodes[i]);
    }

    for (auto i0 = 0, i1 = 1; i1 < xNodes.size(); i0 = i1++)
    {
        if ((errors[i0] > T{} && errors[i1] > T{}) ||
            (errors[i0] < T{} && errors[i1] < T{}))
        {
            // 当误差不振荡时，该过程终止。
            return false;
        }
    }
    return true;
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputePartition()
{
    /// 定义E(x) = F(x) - P(x)。使用平分来计算E(x)的根。
    /// 该算法将[xMin, xMax] 划分为degree+2个子区间，每个子区间的 E(x) 为正或 E(x) 为负。
    /// 随后，使用二次拟合线搜索算法计算子区间上的局部极值。极端位置将成为下一组x节点。
    partition.front() = inputXMin;
    partition.back() = inputXMax;
    for (auto i0 = 0, i1 = 1; i1 < xNodes.size(); i0 = i1++)
    {
        auto x0 = xNodes[i0];
        auto x1 = xNodes[i1];
        T xMid{};
        T eMid{};
        auto sign0 = (errors[i0] > T{} ? 1 : -1);
        auto sign1 = (errors[i1] > T{} ? 1 : -1);
        auto signMid = 0;

        auto iteration = 0;
        for (iteration = 0; iteration < inputMaxBisectionIterations; ++iteration)
        {
            xMid = Math<T>::GetRational(1, 2) * (x0 + x1);
            if (xMid == x0 || xMid == x1)
            {
                // 对于端点的平均值，我们已达到浮点精度的极限。
                break;
            }

            // 将正确的端点更新为中点。
            eMid = inputFunction(xMid) - EvaluateP(xMid);
            signMid = (eMid > T{} ? 1 : (eMid < T{} ? -1 : 0));
            if (signMid == sign0)
            {
                x0 = xMid;
            }
            else if (signMid == sign1)
            {
                x1 = xMid;
            }
            else
            {
                // 找到根（数字四舍五入为零）。
                break;
            }
        }

        // 有可能在没有收敛的情况下应用了最大数量的平分。使用上次计算的xMid作为根。
        partition[i1] = xMid;
    }
}

template <typename T>
void Mathematics::RemezAlgorithm<T>::ComputeXExtremes()
{
    Container nextXNodes(xNodes.size());
    nextXNodes[0] = inputXMin;
    for (auto i0 = 1, i1 = 2; i0 < inputDegree + 1; i0 = i1++)
    {
        nextXNodes[i0] = GetXExtreme(partition[i0], partition[i1]);
    }
    nextXNodes[inputDegree + 1] = inputXMax;
    xNodes = nextXNodes;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::GetXExtreme(T x0, T x1)
{
    auto eder0 = inputFunctionDer(x0) - EvaluatePDer(x0);
    auto eder1 = inputFunctionDer(x1) - EvaluatePDer(x1);
    auto signEDer0 = (eder0 > T{} ? 1 : (eder0 < T{} ? -1 : 0));
    auto signEDer1 = (eder1 > T{} ? 1 : (eder1 < T{} ? -1 : 0));
    if (!(signEDer0 * signEDer1 == -1))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("区间[x0,x1]不绑定根。"))
    }

    T xmid{};
    T ederMid{};

    auto signEMid = 0;
    for (auto i = 0; i < inputMaxBisectionIterations; ++i)
    {
        xmid = Math<T>::GetRational(1, 2) * (x0 + x1);
        if (xmid == x0 || xmid == x1)
        {
            return xmid;
        }

        ederMid = inputFunctionDer(xmid) - EvaluatePDer(xmid);
        signEMid = (ederMid > T{} ? 1 : (ederMid < T{} ? -1 : 0));
        if (signEMid == signEDer0)
        {
            x0 = xmid;
        }
        else if (signEMid == signEDer1)
        {
            x1 = xmid;
        }
        else
        {
            break;
        }
    }
    return xmid;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::EvaluateU(const T& x)
{
    auto index = uCoefficients.size() - 1;
    auto result = uCoefficients[index--];
    for (auto i = 1; i < uCoefficients.size(); ++i, --index)
    {
        result = uCoefficients[index] + (x - xNodes[index]) * result;
    }
    return result;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::EvaluateV(const T& x)
{
    auto index = vCoefficients.size() - 1;
    auto result = vCoefficients[index--];
    for (auto i = 1; i < vCoefficients.size(); ++i, --index)
    {
        result = vCoefficients[index] + (x - xNodes[index]) * result;
    }
    return result;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::EvaluateP(const T& x)
{
    auto index = coefficients.size() - 1;
    auto result = coefficients[index--];
    for (auto i = 1; i < coefficients.size(); ++i, --index)
    {
        result = coefficients[index] + x * result;
    }
    return result;
}

template <typename T>
T Mathematics::RemezAlgorithm<T>::EvaluatePDer(const T& x)
{
    auto index = coefficients.size() - 1;
    auto result = static_cast<T>(index) * coefficients[index];
    --index;
    for (auto i = 2; i < coefficients.size(); ++i, --index)
    {
        result = static_cast<T>(index) * coefficients[index] + x * result;
    }
    return result;
}

#endif  // MATHEMATICS_ESTIMATE_REMEZ_ALGORITHM_DETAIL_H
