///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:53)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_DETAIL_H

#include "Surface.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SURFACE_DETAIL)

    #ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Surface<Real>::IsValid() const noexcept
{
    return true;
}

    #endif  // OPEN_CLASS_INVARIANT

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SURFACE_DETAIL)

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_DETAIL_H