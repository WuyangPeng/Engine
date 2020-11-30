///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// 二分法解方程的根
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1Root final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect1Root<Real>;

    public:
        // 方程无解
        Bisect1Root() noexcept;
        // 方程有解
        Bisect1Root(Real root, BisectRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 当m_Bisect1RootType == Bisect1RootTypeHaveSolution时，
        // m_Root是有效的。
        // 当m_Bisect1RootType == Bisect1RootTypeUnknown时，
        // m_Root是近似值，不保证结果是正确的。
        // 当m_Bisect1RootType == Bisect1RootTypeNoSolution时，
        // GetRoot()抛出异常。
        [[nodiscard]] Real GetRoot() const;
        [[nodiscard]] BisectRootType GetBisect1RootType() const noexcept;

    private:
        Real m_Root;
        BisectRootType m_Bisect1RootType;
    };

    using FloatBisect1Root = Bisect1Root<float>;
    using DoubleBisect1Root = Bisect1Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
