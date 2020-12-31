///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 14:12)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_DETAIL_H

#include "IntersectorConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::IntersectorConfigurationImpl<Real>::IntersectorConfigurationImpl() noexcept
    : m_Map{}, m_Index{}, m_Min{}, m_Max{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::IntersectorConfigurationImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VertexProjectionMap Mathematics::IntersectorConfigurationImpl<Real>::GetMap() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Map;
}

template <typename Real>
void Mathematics::IntersectorConfigurationImpl<Real>::SetMap(VertexProjectionMap vertexProjectionMap) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Map = vertexProjectionMap;
}

template <typename Real>
Real Mathematics::IntersectorConfigurationImpl<Real>::GetMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Min;
}

template <typename Real>
void Mathematics::IntersectorConfigurationImpl<Real>::SetMin(Real min) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Min = min;
}

template <typename Real>
Real Mathematics::IntersectorConfigurationImpl<Real>::GetMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Max;
}

template <typename Real>
void Mathematics::IntersectorConfigurationImpl<Real>::SetMax(Real max) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Max = max;
}

template <typename Real>
int Mathematics::IntersectorConfigurationImpl<Real>::GetIndex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Index.at(index);
}

template <typename Real>
void Mathematics::IntersectorConfigurationImpl<Real>::SetIndex(int index, int value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Index.at(index) = value;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_IMPL_DETAIL_H