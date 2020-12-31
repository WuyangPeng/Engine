///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 14:37)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H

#include "GreatArcFit3Item.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::GreatArcFit3Item<Real>::GreatArcFit3Item(const Vector3D& uVector, const Vector3D& vVector, const Vector3D& point)
    : m_UDot{ Vector3DTools<Real>::DotProduct(uVector, point) }, m_VDot{ Vector3DTools<Real>::DotProduct(vVector, point) }, m_Angle{ Math<Real>::ATan2(m_VDot, m_UDot) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GreatArcFit3Item<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>::GetUDot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_UDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>::GetVDot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_VDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>::GetAngle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Angle;
}

template <typename Real>
bool Mathematics::operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs)
{
    return lhs.GetAngle() < rhs.GetAngle();
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H