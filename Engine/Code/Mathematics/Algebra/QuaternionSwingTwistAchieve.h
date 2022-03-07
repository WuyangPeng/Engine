///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 13:59)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_ACHIEVE_H

#include "Quaternion.h"
#include "QuaternionSwingTwist.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QuaternionSwingTwist<Real>::QuaternionSwingTwist(const Quaternion& swing, const Quaternion& twist) noexcept
    : swing{ swing }, twist{ twist }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuaternionSwingTwist<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::QuaternionSwingTwist<Real>::GetTwist() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return twist;
}

template <typename Real>
Mathematics::Quaternion<Real> Mathematics::QuaternionSwingTwist<Real>::GetSwing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return swing;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_ACHIEVE_H
