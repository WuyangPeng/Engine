///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/14 22:27)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_SPHERE_COORDINATES_ACHIEVE

        #define MATHEMATICS_INCLUDED_SPHERE_COORDINATES_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_SPHERE_COORDINATES_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "SphereCoordinatesDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class SphereCoordinates<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class SphereCoordinates<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE