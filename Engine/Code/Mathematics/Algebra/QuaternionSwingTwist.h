///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/08 13:58)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
#define MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionSwingTwist final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = QuaternionSwingTwist<Real>;
        using Quaternion = Quaternion<Real>;

    public:
        QuaternionSwingTwist(const Quaternion& swing, const Quaternion& twist) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Quaternion GetTwist() const noexcept;
        NODISCARD Quaternion GetSwing() const noexcept;

    private:
        Quaternion swing;
        Quaternion twist;
    };

    using QuaternionSwingTwistF = QuaternionSwingTwist<float>;
    using QuaternionSwingTwistD = QuaternionSwingTwist<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
