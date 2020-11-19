///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 15:40)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_ACHIEVE_H

#include "Capsule3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Capsule3<Real>::Capsule3(const Segment3& segment, Real radius) noexcept
    : m_Segment{ segment }, m_Radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Capsule3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::Capsule3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Segment;
}

template <typename Real>
Real Mathematics::Capsule3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Radius;
}

#endif  // MATHEMATICS_OBJECTS3D_CAPSULE3_ACHIEVE_H