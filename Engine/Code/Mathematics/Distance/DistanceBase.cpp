///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/19 22:14)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE
        #define MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "DistanceBaseDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector2<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector2<double>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector3<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector3<double>>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
