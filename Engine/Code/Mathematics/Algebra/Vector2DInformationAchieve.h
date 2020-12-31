///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 19:10)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_ACHIEVE_H

#include "AxesAlignBoundingBox2D.h"
#include "Vector2DInformation.h"
#include "Detail/Vector2DInformationImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2DInformation<Real>::Vector2DInformation(const ContainerType& points, Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(points, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2DInformation<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Vector2DInformation<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDimension();
}

template <typename Real>
typename Mathematics::Vector2DInformation<Real>::AxesAlignBoundingBox2D Mathematics::Vector2DInformation<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetAABB();
}

template <typename Real>
Real Mathematics::Vector2DInformation<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxRange();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetOrigin();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDirectionX();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDirectionY();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMinExtreme();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxExtreme();
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPerpendicularExtreme();
}

template <typename Real>
bool Mathematics::Vector2DInformation<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsExtremeCCW();
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMinExtremeIndex();
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPerpendicularExtremeIndex();
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMaxExtremeIndex();
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>::GetIndexMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIndexMin(index);
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_ACHIEVE_H