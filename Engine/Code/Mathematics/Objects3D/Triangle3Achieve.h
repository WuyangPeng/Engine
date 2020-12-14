///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 17:00)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_ACHIEVE_H

#include "Triangle3.h"
#include "Detail/Triangle3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Triangle3<Real>::Triangle3(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2)
    : m_Impl{ std::make_shared<ImplType>(vector0, vector1, vector2) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Triangle3<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::Triangle3<Real>::ContainerType Mathematics::Triangle3<Real>::GetVertex() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertex();
}

template <typename Real>
const typename Mathematics::Triangle3<Real>::ContainerType Mathematics::Triangle3<Real>::GetEdgeVectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEdgeVectors();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Triangle3<Real>::GetNormal() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNormal();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Triangle3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertex(index);
}

template <typename Real>
Real Mathematics::Triangle3<Real>::DistanceTo(const Vector3D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->DistanceTo(point);
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::Triangle3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Triangle3{ GetVertex(0) + t * velocity, GetVertex(1) + t * velocity, GetVertex(2) + t * velocity };
}

#endif  // MATHEMATICS_OBJECTS3D_TRIANGLE3_ACHIEVE_H
