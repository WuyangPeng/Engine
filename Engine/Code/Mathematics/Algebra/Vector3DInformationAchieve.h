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
    : m_Impl{ std::make_shared<ImplType>(points, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3DInformation<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDimension();
}

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real> Mathematics::Vector3DInformation<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAABB();
}

template <typename Real>
Real Mathematics::Vector3DInformation<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxRange();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetOrigin();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDirectionX();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDirectionY();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetDirectionZ() const noexcept
{ 
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDirectionZ();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMinExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPerpendicularExtreme();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformation<Real>::GetTetrahedronExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTetrahedronExtreme();
}

template <typename Real>
bool Mathematics::Vector3DInformation<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsExtremeCCW();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMinExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPerpendicularExtremeIndex();
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>::GetTetrahedronExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTetrahedronExtremeIndex();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_ACHIEVE_H