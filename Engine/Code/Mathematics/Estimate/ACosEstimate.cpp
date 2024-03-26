/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 00:00)

#include "Mathematics/MathematicsExport.h"

#include "ACosEstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void ACosEstimateInstance()
    {
        MAYBE_UNUSED const auto aCosEstimate = ACosEstimate<float, 5>(0.0f);
        MAYBE_UNUSED constexpr auto maxError = GetACosEstimateMaxError<float, 5>();
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
