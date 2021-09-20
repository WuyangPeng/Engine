///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 11:18)

#ifndef MATHEMATICS_OBJECTS2D_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_TRIANGLE2_ACHIEVE_H

#include "Triangle2.h"
#include "Detail/Triangle2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Triangle2<Real>::Triangle2(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2)
    : impl{  vector0, vector1, vector2  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Triangle2<Real>::IsValid() const noexcept
{
    
        return true;
    
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Triangle2<Real>::ContainerType Mathematics::Triangle2<Real>::GetVertex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetVertex();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Triangle2<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetVertex(index);
}

template <typename Real>
Real Mathematics::Triangle2<Real>::DistanceTo(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->DistanceTo(point);
}

#endif  // MATHEMATICS_OBJECTS2D_TRIANGLE2_ACHIEVE_H
