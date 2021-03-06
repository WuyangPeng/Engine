///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 17:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// 二分法解方程的根
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect3Root final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Root<Real>;

    public:
        // 方程无解
        Bisect3Root() noexcept;
        // 方程有解
        Bisect3Root(Real xRoot, Real yRoot, Real zRoot, BisectRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 当m_BisectRootType == BisectRootType::HaveSolution时，
        // m_XRoot、m_YRoot、m_ZRoot是有效的。
        // 当m_BisectRootType == BisectRootType::Unknown时，
        // m_XRoot、m_YRoot、m_ZRoot是近似值，不保证结果是正确的。
        // 当m_BisectRootType == BisectRootType::NoSolution时，
        // GetXRoot()、GetYRoot()、GetZRoot()抛出异常。
        [[nodiscard]] Real GetXRoot() const;
        [[nodiscard]] Real GetYRoot() const;
        [[nodiscard]] Real GetZRoot() const;
        [[nodiscard]] BisectRootType GetBisectRootType() const noexcept;

    private:
        Real m_XRoot;
        Real m_YRoot;
        Real m_ZRoot;
        BisectRootType m_BisectRootType;
    };

    using FloatBisect3Root = Bisect3Root<float>;
    using DoubleBisect3Root = Bisect3Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
