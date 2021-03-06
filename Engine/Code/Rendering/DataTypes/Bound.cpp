///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 17:15)

#include "Rendering/RenderingExport.h"

#ifdef RENDERING_EXPORT_TEMPLATE

    #ifndef RENDERING_INCLUDED_BOUND_ACHIEVE
        #define RENDERING_INCLUDED_BOUND_ACHIEVE
    #endif  // RENDERING_INCLUDED_BOUND_ACHIEVE

#endif  // RENDERING_EXPORT_TEMPLATE

#include "BoundDetail.h"

#ifdef RENDERING_EXPORT_TEMPLATE

namespace Rendering
{
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Bound<float>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Bound<double>;
}

#endif  // RENDERING_EXPORT_TEMPLATE

 