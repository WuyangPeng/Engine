///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:41)

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
        NODISCARD Real GetXRoot() const;
        NODISCARD Real GetYRoot() const;
        NODISCARD Real GetZRoot() const;
        NODISCARD BisectRootType GetBisectRootType() const noexcept;

    private:
        Real xRoot;
        Real yRoot;
        Real zRoot;
        BisectRootType bisectRootType;
    };

    using Bisect3RootF = Bisect3Root<float>;
    using Bisect3RootD = Bisect3Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
