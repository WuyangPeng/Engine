///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 18:37)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H

#include "GreatArcFit3Item.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::GreatArcFit3Item<Real>::GreatArcFit3Item(const Vector3& uVector, const Vector3& vVector, const Vector3& point) noexcept
    : uDot{ Vector3Tools<Real>::DotProduct(uVector, point) }, vDot{ Vector3Tools<Real>::DotProduct(vVector, point) }, angle{ Math<Real>::ATan2(vDot, uDot) }
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
Real Mathematics::GreatArcFit3Item<Real>::GetUDot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>::GetVDot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <typename Real>
bool Mathematics::operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs) noexcept
{
    return lhs.GetAngle() < rhs.GetAngle();
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H