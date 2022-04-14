///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/13 15:01)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_CURVE2_DETAIL
        #define MATHEMATICS_INCLUDED_CURVE2_DETAIL
    #endif  // MATHEMATICS_INCLUDED_CURVE2_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Curve2Detail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Curve2<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Curve2<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
