///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 11:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

/// 支持对奇异值进行排序。
namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SingularInfo
    {
    public:
        using ClassType = SingularInfo<Real>;

    public:
        SingularInfo() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSingular() const noexcept;
        void SetSingular(Real aSingular) noexcept;
        NODISCARD int GetInversePermute() const noexcept;
        void SetInversePermute(int aInversePermute) noexcept;

    private:
        Real singular;
        int inversePermute;
    };

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const SingularInfo<Real>& lhs, const SingularInfo<Real>& rhs) noexcept;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_INFO_H
