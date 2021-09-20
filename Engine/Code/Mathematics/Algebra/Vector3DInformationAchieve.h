///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 18:43)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_ACHIEVE_H

#include "AxesAlignBoundingBox3D.h"
#include "Vector3DInformation.h"
#include "Vector3DTools.h"
#include "Detail/Vector3DInformationImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector3DInformation<Real>::Vector3DInformation(const ContainerType& points, Real epsilon)
    : impl{  points, epsilon  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3DInformation<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDimension();
}

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real> Mathematics::Vector3DInformation<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetAABB();
}

template <typename Real>
Real Mathematics::Vector3DInformation<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMaxRange();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetOrigin();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDirectionX();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDirectionY();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionZ() const noexcept
{ 
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDirectionZ();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMinExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMaxExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPerpendicularExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetTetrahedronExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTetrahedronExtreme();
}

template <typename Real>
bool Mathematics::Vector3DInformation<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->IsExtremeCCW();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMinExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMaxExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPerpendicularExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetTetrahedronExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTetrahedronExtremeIndex();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_ACHIEVE_H