///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/29 10:47)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL
        #define MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL
    #endif  // MATHEMATICS_INCLUDED_FAST_NEGATIVE_EXP_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "FastNegativeExpDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FastNegativeExp<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FastNegativeExp<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
