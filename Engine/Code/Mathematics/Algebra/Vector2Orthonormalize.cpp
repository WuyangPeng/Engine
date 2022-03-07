///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 23:45)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_VECTOR2_ORTHONORMALIZE_ACHIEVE
        #define MATHEMATICS_INCLUDED_VECTOR2_ORTHONORMALIZE_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_VECTOR2_ORTHONORMALIZE_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Vector2OrthonormalizeDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector2Orthonormalize<float, false>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector2Orthonormalize<double, false>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector2Orthonormalize<float, true>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector2Orthonormalize<double, true>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
