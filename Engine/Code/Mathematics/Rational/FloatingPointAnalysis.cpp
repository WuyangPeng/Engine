/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:30)

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