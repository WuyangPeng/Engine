///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/09 9:50)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H

#include "Matrix3Extract.h"
#include "Vector3D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Matrix3Extract<Real>::Matrix3Extract(Real angle, const Vector3D& axis) noexcept
    : m_Angle{ angle }, m_Axis{ axis }
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

    return m_Angle;
}

template <typename Real>
typename const Mathematics::Matrix3Extract<Real>::Vector3D Mathematics::Matrix3Extract<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Axis;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_ACHIEVE_H
