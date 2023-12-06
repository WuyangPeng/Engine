/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/05 10:28)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_BOUNDING_SPHERE_ACHIEVE

        #define MATHEMATICS_INCLUDED_BOUNDING_SPHERE_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_BOUNDING_SPHERE_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "BoundingSphereDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class BoundingSphere<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class BoundingSphere<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
