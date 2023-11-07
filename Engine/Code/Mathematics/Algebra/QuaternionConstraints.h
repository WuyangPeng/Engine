///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:55)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H
#define MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    // 查找最近的四元数使用约束的角度。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionConstraints final
    {
    public:
        using ClassType = QuaternionConstraints<Real>;

        using Quaternion = Quaternion<Real>;
        using Math = Math<Real>;

    public:
        QuaternionConstraints(Real minAngle, Real maxAngle) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsValid(Real x, Real y) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD Real GetCosMinAngle() const noexcept;
        NODISCARD Real GetSinMinAngle() const noexcept;
        NODISCARD Real GetCosMaxAngle() const noexcept;
        NODISCARD Real GetSinMaxAngle() const noexcept;
        NODISCARD Real GetCosAvrAngle() const noexcept;
        NODISCARD Real GetSinAvrAngle() const noexcept;
        NODISCARD Real GetMinAngle() const noexcept;
        NODISCARD Real GetMaxAngle() const noexcept;

    private:
        Real minAngle;  // 在 [-PI/2,PI/2]
        Real maxAngle;  // 在 [m_fMinAngle/2,PI/2]
        Real cosMinAngle;  // = cos(m_fMinAngle)
        Real sinMinAngle;  // = sin(m_fMinAngle)
        Real cosMaxAngle;  // = cos(m_fMaxAngle)
        Real sinMaxAngle;  // = sin(m_fMaxAngle)
        Real diffCosMaxMin;  // = cos(m_fMaxAngle) - cos(m_fMinAngle)
        Real diffSinMaxMin;  // = sin(m_fMaxAngle) - sin(m_fMinAngle)
        Real avrAngle;
        Real cosAvrAngle;  // = cos((m_fMinAngle + m_fMaxAngle)/2)
        Real sinAvrAngle;  // = sin((m_fMinAngle + mM_faxAngle)/2)
    };

    using QuaternionConstraintsF = QuaternionConstraints<float>;
    using QuaternionConstraintsD = QuaternionConstraints<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_H
