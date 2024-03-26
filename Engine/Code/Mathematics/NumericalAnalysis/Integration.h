/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 14:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <functional>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Integration
    {
    public:
        using ClassType = Integration<Real>;

        using Math = Math<Real>;

    public:
        Integration() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 这是一种简单的算法，但随着样本数量的增加，收敛速度较慢。
        /// “numSamples”必须大于或等于两个。
        NODISCARD static Real TrapezoidRule(int numSamples, Real a, Real b, const std::function<Real(Real)>& integrand);

        /// 梯形规则用于生成初始估计，但随后使用Richardson外推法来改进估计。
        /// 这比TrapezoidRule更可取。
        /// “顺序”必须为正。
        NODISCARD static Real Romberg(int order, Real a, Real b, const std::function<Real(Real)>& integrand);

        /// 高斯求积估计在[-1,1]上定义的函数f(x)的积分，
        /// 使用integral_{-1}^{1} f(t) dt = sum_{i=0}^{n-1} c[i]*f(r[i])，
        /// 其中r[i]是n次勒让德多项式p(t)的根，并且
        /// c[i] = integral_{-1}^{1} prod_{j=0,j!=i} (t-r[j]/(r[i]-r[j]) dt
        /// 为了在[a,b]上积分，在内部应用对[-1,1]的变换：x - ((b-a)*t + (b+a))/2。
        /// 勒让德多项式由生成
        ///   P[0](x) = 1, P[1](x) = x,
        ///   P[k](x) = ((2*k-1)*x*P[k-1](x) - (k-1)*P[k-2](x))/k, k >= 2
        /// 实现多项式生成很简单，并且计算根需要找到多项式根的数值方法。
        /// 具有挑战性的任务是开发一种有效的算法来计算特定程度的系数 c[i]。
        /// “度”必须为2或更大。

        static void ComputeQuadratureInfo(int degree, std::vector<Real>& roots, std::vector<Real>& coefficients);

        NODISCARD static Real GaussianQuadrature(const std::vector<Real>& roots, const std::vector<Real>& coefficients, Real a, Real b, const std::function<Real(Real)>& integrand);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_H
