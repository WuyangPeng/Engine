///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:08)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_FLOATING_POINT_ANALYSIS_ACHIEVE
        #define MATHEMATICS_INCLUDED_FLOATING_POINT_ANALYSIS_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_FLOATING_POINT_ANALYSIS_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "FloatingPointAnalysisDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FloatingPointAnalysis<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class FloatingPointAnalysis<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE