///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:00)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
#define MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionSwingTwist final
    {
    public:
        using ClassType = QuaternionSwingTwist<Real>;

        using QuaternionType = Quaternion<Real>;

    public:
        QuaternionSwingTwist(const QuaternionType& swing, const QuaternionType& twist) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD QuaternionType GetTwist() const noexcept;
        NODISCARD QuaternionType GetSwing() const noexcept;

    private:
        QuaternionType swing;
        QuaternionType twist;
    };

    using QuaternionSwingTwistF = QuaternionSwingTwist<float>;
    using QuaternionSwingTwistD = QuaternionSwingTwist<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
