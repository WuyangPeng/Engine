///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/14 14:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BrentsMethodRoot final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethodRoot<Real>;

    public:
        // 方程无解
        BrentsMethodRoot() noexcept;
        // 方程有解
        BrentsMethodRoot(Real root, Real function, BrentsMethodRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetRoot() const;
        NODISCARD Real GetFunction() const;
        NODISCARD BrentsMethodRootType GetBrentsMethodRootType() const noexcept;

    private:
        Real root;
        Real function;
        BrentsMethodRootType brentsMethodRootType;
    };

    using BrentsMethodRootF = BrentsMethodRoot<float>;
    using BrentsMethodRootD = BrentsMethodRoot<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
