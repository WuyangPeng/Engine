///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 15:29)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_FAST_TRIGONOMETRIC_DETAIL
        #define MATHEMATICS_INCLUDED_FAST_TRIGONOMETRIC_DETAIL
    #endif  // MATHEMATICS_INCLUDED_FAST_TRIGONOMETRIC_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "FastTrigonometricDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FastTrigonometric<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FastTrigonometric<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
