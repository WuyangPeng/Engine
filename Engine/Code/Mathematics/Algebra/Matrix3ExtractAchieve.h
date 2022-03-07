///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 17:02)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H

#include "Matrix3Extract.h"
#include "Vector3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Matrix3Extract<Real>::Matrix3Extract(Real angle, const Vector3& axis) noexcept
    : angle{ angle }, axis{ axis }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Matrix3Extract<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Matrix3Extract<Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <typename Real>
typename Mathematics::Matrix3Extract<Real>::Vector3 Mathematics::Matrix3Extract<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H
