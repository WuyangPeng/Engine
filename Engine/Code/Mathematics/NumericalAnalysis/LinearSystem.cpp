///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 12:51)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_LINEAR_SYSTEM_ACHIEVE
        #define MATHEMATICS_INCLUDED_LINEAR_SYSTEM_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_LINEAR_SYSTEM_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "LinearSystemDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class LinearSystem<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class LinearSystem<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
