///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:23)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H

#include "IntersectorConfiguration.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::IntersectorConfiguration<Real>::IntersectorConfiguration() noexcept
    : vertexProjectionMap{}, indexType{}, min{}, max{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntersectorConfiguration<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VertexProjectionMap Mathematics::IntersectorConfiguration<Real>::GetMap() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertexProjectionMap;
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMap(VertexProjectionMap newVertexProjectionMap) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertexProjectionMap = newVertexProjectionMap;
}

template <typename Real>
Real Mathematics::IntersectorConfiguration<Real>::GetMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return min;
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMin(Real newMin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    min = newMin;
}

template <typename Real>
Real Mathematics::IntersectorConfiguration<Real>::GetMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return max;
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetMax(Real newMax) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    max = newMax;
}

template <typename Real>
int Mathematics::IntersectorConfiguration<Real>::GetIndex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indexType.at(index);
}

template <typename Real>
void Mathematics::IntersectorConfiguration<Real>::SetIndex(int index, int value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    indexType.at(index) = value;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H