///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:06)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_SURFACE_DETAIL

        #define MATHEMATICS_INCLUDED_SURFACE_DETAIL

    #endif  // MATHEMATICS_INCLUDED_SURFACE_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "SurfaceDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Surface<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Surface<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
