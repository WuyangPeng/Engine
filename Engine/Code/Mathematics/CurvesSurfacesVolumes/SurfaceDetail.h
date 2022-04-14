///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 10:49)

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