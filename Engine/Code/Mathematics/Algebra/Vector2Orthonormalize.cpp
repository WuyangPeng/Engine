///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:09)

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
