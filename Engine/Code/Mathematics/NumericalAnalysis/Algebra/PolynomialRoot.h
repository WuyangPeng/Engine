/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 13:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <functional>

/// 支持计算1、2、3或4次多项式的根。
namespace Mathematics::Algebra
{
    template <typename Real>
    class PolynomialRoot
    {
    public:
        using ClassType = PolynomialRoot<Real>;

        using MathType = Math<Real>;

    public:
        NODISCARD static PolynomialRoot CreateZero() noexcept(noexcept(Real::CreateZero())) requires(!std::is_floating_point_v<Real>);
        NODISCARD static PolynomialRoot CreateZero() noexcept requires(std::is_floating_point_v<Real>);

        PolynomialRoot() noexcept requires(std::is_floating_point_v<Real>);
        PolynomialRoot(Real x, int m) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetX() const noexcept;
        NODISCARD int GetM() const noexcept;

        void SetX(Real aX) noexcept;
        void SetM(int aM) noexcept;

        /// 计算多项式F(x)的根的紧区间[xMin,xMax]。
        /// 输入signFMin和signFMax在{-1,1}中，并且是初始xMin和xMax的F(xMin)和F(xMax)的理论符号。
        /// 他们被要求有相反的标志。为了提高速度，使用浮点运算执行二等分。
        static void PolynomialRootBisect(const std::function<Real(Real)>& function, int signFMin, int signFMax, Real& xMin, Real& xMax) requires(std::is_arithmetic_v<Real>);
        static void PolynomialRootBisect(const std::function<Real(Real)>& function, int signFMin, int signFMax, Real& xMin, Real& xMax) requires(!std::is_arithmetic_v<Real>);

    private:
        /// x是根估计 ，m是x的多重性。
        /// 当m为0时，对象无效。
        Real x;
        int m;
    };

    template <typename Real>
    NODISCARD bool operator==(const PolynomialRoot<Real>& lhs, const PolynomialRoot<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool operator<(const PolynomialRoot<Real>& lhs, const PolynomialRoot<Real>& rhs) noexcept;

}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_H
